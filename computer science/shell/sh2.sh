#!/usr/bin/bash
echo "hello world"
# 变量
v=12 #等号两边没有空格
q="hello"
echo ${v} # $加变量名，最好加上{}
echo ${q}
for i in `ls` ;do #``是反斜号，表示运行之间的命令
echo ${i}
done
for j in hh jj kk ll; do
echo ${j}
done
# shell 中的字符串
# 单引号：
# 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的；
# 单引号字串中不能出现单引号（对单引号使用转义符后也不行）。
# 双引号：
#	双引号里可以有变量
#	双引号里可以出现转义字符
s='sjhdsj\sdj\t\n'
ss="shsdjsdj\nsjj$q"
echo ${s}
echo ${ss}
#sjhdsj\sdj\t\n
#shsdjsdj\nsjjhello
your_name='qinjx'
str="Hello, I know your are \"$your_name\"! \n"
echo ${str}
#其他一次额操作：http://www.runoob.com/linux/linux-shell-variable.html
# Shell中的数组
ar=(1 2 3 2 1)
echo ${ar[1]} ${ar[2]} #2 3
ar[2]=100
ar[10]=90
echo ${ar[2]} ${ar[10]} #100 90
echo ${ar[@]} # 1 2 100 2 1 90
for i in ${ar[@]};do
echo ${i}
done
#取得数组元素个数
echo ${#ar[@]}
sa=(shh sds qwqwqwq swdsd)
echo ${sa[2]}
echo ${sa[@]}
#取得字符的串字符数目，以及取得字符串数组个数
echo ${#sa[1]} #3
echo ${#sa[@]} #4
# Shell 传递参数，$0 为执行文件名 $1第一个参数， 。。。
# 运行的时候，./myshell.sh 12 34
echo $0 #./myshell.sh
echo $1 # 12
#其他一些问题，
# 参数处理	说明
# $#	传递到脚本的参数个数
# $*	以一个单字符串显示所有向脚本传递的参数。
# 如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。
# $$	脚本运行的当前进程ID号
# $!	后台运行的最后一个进程的ID号
# $@	与$*相同，但是使用时加引号，并在引号中返回每个参数。
# 如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。
# $-	显示Shell使用的当前选项，与set命令功能相同。
# $?	显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。
# @ * 区别！！！
for i in "$*"; do
echo $i
done
for i in "$@"; do
echo $i
done
# 流程控制
#if
a=10
b=20
if [ $a == $b ]
then
echo "a equal b"
elif [ $a -gt $b ]
then
echo "a greater b"
elif [ $a -lt $b ]
then
echo "a less b"
else
echo "no"
fi
for var in item1 item2 ... itemN
do
 # command1
 # command2
 # ...
 # commandN
echo ${var}
done
# Shell 函数
funWithParam(){
echo "第一个参数为 $1 !"
echo "第二个参数为 $2 !"
echo "第十个参数为 $10 !"
echo "第十个参数为 ${10} !"
echo "第十一个参数为 ${11} !"
echo "参数总数有 $# 个!"
echo "作为一个字符串输出所有参数 $* !"
	return 1
}
funWithParam 1 2 3 4 5 6 7 8 9 34 73
echo $?
# 使用 source ./file 或者 . ./file 包含文件