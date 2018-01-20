import argparse
from stations import stations
import requests
from prettytable import PrettyTable

parser = argparse.ArgumentParser()

parser.add_argument('-g', action='store_true', default=False,
        dest='gaotie',
        help='查询高铁')
parser.add_argument('-d', action='store_true', default=False,
        dest='dongche',
        help='查询动车')
parser.add_argument('-t', action='store_true', default=False,
        dest='tekuai',
        help='查询特快')
parser.add_argument('-k', action='store_true', default=False,
        dest='kuaisu',
        help='查询快速')
parser.add_argument('-z', action='store_true', default=False,
        dest='zhida',
        help='查询直达')
parser.add_argument('From', action="store",help='起始站')
parser.add_argument('To', action="store",help='终点站')
parser.add_argument('Date', action="store",help='时间（eg: 2016-08-25)')
args = parser.parse_args()


def colored(color, text):
    table = {
        'red': '\033[91m',
        'green': '\033[92m',
        # no color
        'nc': '\033[0m'
    }
    cv = table.get(color)
    nc = table.get('nc')
    return ''.join([cv, text, nc])


class TrainCollection(object):

    # 显示车次、出发/到达站、 出发/到达时间、历时、一等坐、二等坐、软卧、硬卧、硬座
    header = 'train station time duration first second softsleep hardsleep hardsit'.split()

    def __init__(self, rows):
        self.rows = rows

    def _get_duration(self, row):
        """
        获取车次运行时间
        """
        duration = row.get('lishi').replace(':', 'h') + 'm'
        if duration.startswith('00'):
            return duration[4:]
        if duration.startswith('0'):
            return duration[1:]
        return duration

    @property
    def trains(self):
        for row in self.rows:
            train = [
                # 车次
                row['station_train_code'],
                # 出发、到达站
                '\n'.join([colored('green', row['from_station_name']),
                           colored('red', row['to_station_name'])]),
                # 出发、到达时间
                '\n'.join([colored('green', row['start_time']),
                           colored('red', row['arrive_time'])]),
                # 历时
                self._get_duration(row),
                # 一等坐
                row['zy_num'],
                # 二等坐
                row['ze_num'],
                # 软卧
                row['rw_num'],
                # 软坐
                row['yw_num'],
                # 硬坐
                row['yz_num']
            ]
            yield train

    def pretty_print(self):
        """
        数据已经获取到了，剩下的就是提取我们要的信息并将它显示出来。
        `prettytable`这个库可以让我们它像MySQL数据库那样格式化显示数据。
        """
        pt = PrettyTable()
        # 设置每一列的标题
        pt._set_field_names(self.header)
        for train in self.trains:
            pt.add_row(train)
        print(pt)

def cli():
    from_station = stations.get(args.From)
    to_station = stations.get(args.To)
    date = args.Date
    url = 'https://kyfw.12306.cn/otn/lcxxcx/query?purpose_codes=ADULT&queryDate=%s&from_station=%s&to_station=%s' % (
    date, from_station, to_station)
    r = requests.get(url, verify=False)
    rows = r.json()['data']['datas']
    trains = TrainCollection(rows)
    trains.pretty_print()

if __name__ == '__main__':
    cli()