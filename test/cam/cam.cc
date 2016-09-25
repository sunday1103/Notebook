#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000 /* the loop count */

/* function: do loop operation

 * input: NULL

 * output: counter->the counter result

 */

bool task_mapping_cona(application &app)
{
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    updateNeighborsFreePE();
    int task_num = app.tasks.size();
    running_app_state[app.app_id].resize(task_num);
    petable[0].busy = 1;

    if (pecount < app.tasks.size())
    {
        return 0;
    }
    int firstTask = app.firstTask;
    int firstNode = first_node(task_num);
    if (petable[firstNode].neighborsFreeNum < 2)
    {
        return 0;
    }
    vector<vector<int> > task_order = app.task_order;
    cout << "mapping result for App " << app.app_id << " :" << endl;
    // mapping
    petable[firstNode].busy = 1;
    petable[firstNode].app_id = app.app_id;
    petable[firstNode].task_id = firstTask;
    running_app_state[app.app_id][firstTask] = firstNode;
    // update_link_info_new_node_XY(true, 1, app.app_id, firstTask);
    cout << "task " << firstTask << "\tof application\t" << app.app_id << " -> "
         << "PE\t" << firstNode << endl;
    // updateNeighborsFreePE();
    int size_x = 8;
    int size_y = 8;
    for (int i = 1; i < app.tasks.size(); ++i)
    {
        int current_taskid = task_order[i][0];
        int current_predecessor = task_order[i][1];
        // cout<<"current_predecessor  "<<current_predecessor<<endl;
        int current_predecessor_PE = running_app_state[app.app_id][current_predecessor];
        std::vector<int> nextPeList;

        int hop = 0;
        int minHop = 1000;
        for (int i = 1; i < m_pe_num; ++i)
        {
            if (!petable[i].busy)
            {
                hop = abs(current_predecessor_PE / size_x - i / size_x) +
                      abs(current_predecessor_PE % size_x - i % size_x);
                if (hop < minHop)
                {
                    minHop = hop;
                }
            }
        }

        for (int i = 1; i < m_pe_num; ++i)
        {
            if (!petable[i].busy)
            {
                hop = abs(current_predecessor_PE / size_x - i / size_x) +
                      abs(current_predecessor_PE % size_x - i % size_x);
                if (hop == minHop)
                {
                    nextPeList.push_back(i);
                }
            }
        }

        int squareMin = 1000;
        int square_temp = 0;
        int index = 0;
        for (int i = 0; i < nextPeList.size(); ++i)
        {
            square_temp = max(abs((nextPeList[i] / size_x - firstNode / size_x)),
                              abs((nextPeList[i] % size_x - firstNode % size_x)));
            if (square_temp < squareMin)
            {
                squareMin = square_temp;
                index = i;
            }
        }
        int nextNode = nextPeList[index];

        petable[nextNode].busy = 1;
        petable[nextNode].app_id = app.app_id;
        petable[nextNode].task_id = current_taskid;
        running_app_state[app.app_id][current_taskid] = nextNode;
        cout << "task " << current_taskid << "\tof application\t" << app.app_id << " -> "
             << "PE\t" << nextNode << endl;
        // updateNeighborsFreePE();

        // int interference_factor = get_interference_factor(app.app_id, current_taskid, nextNode, 0);
        // factor_distribution_cona[interference_factor] += 1;
        // update_link_info_new_node_XY(true, 1, app.app_id, current_taskid);
        cout << "search_pes\t" << nextPeList.size() << endl;
    }

    gettimeofday(&end_time, NULL);
    double interval = 1000000 * (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec);
    cout << "timeIs " << interval / 1000.0 << endl;

    update_factor_log();

    // print_interference_factor(app.app_id, 1);
    return 1;
}

int do_work()

{

    int counter = 0; /* the counter */

    int i, j; /* the loop variable */

    /* accumulate the counter */

    for (i = 0; i < MAX; i++)

        for (j = 0; j < MAX; j++)

            counter++;

    /* return the counter's value */

    return counter;
}

int main()
{

    struct timeval start, end;

    int interval;

    gettimeofday(&start, NULL);

    //do_work();
    sleep(2);
    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);

    int a[10000];
    gettimeofday(&start, NULL);

    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            a[j];
        }
    }

    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);

    int *p = a;

    gettimeofday(&start, NULL);

    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
            *(j + p);
        }
    }

    gettimeofday(&end, NULL);

    interval = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);

    printf("interval = %f ms\n", interval / 1000.0);
}