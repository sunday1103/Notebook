import threading
from time import sleep


def job1(lock):
    lock.acquire()
    print(1)
    sleep(1)
    print(2)
    sleep(1)
    print(3)
    sleep(1)
    print(4)
    lock.release()

lock = threading.Lock()

t1 = threading.Thread(target=job1, args=(lock,))
t2 = threading.Thread(target=job1, args=(lock,))
t1.start()
t2.start()