



int step1()
{
    begin_fsm(CMM_FSM, MEAS_CTRL);
    trans_fsm(WAIT_STEP1_OVER)
    do_something
}

int step2()
{
    trans_fsm(WAIT_STEP2_OVER)
    do_something
}

int step2Finish()
{
    endFsm(CMM_FSM)
    do_something, 触发这个状态下的事件。
}


int cfg_phy_handle()
{
    if need step1
        step1()

    if need step2
        step2()
}

int measStart()
{
    begin_fsm(CMM_FSM, MEAS_CTRL);
    trans_fsm(WAIT_PHY_CFG_CNF);

    cfg_phy_handle();
}

int main()
{
    measStart();
    return 0;
}