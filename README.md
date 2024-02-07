# ROB305 - TD

ROB305  ENSTA Paris.

## TD1

### a


```
cd TP1/src
g++  main_tp1a.cpp TimeSpec.cpp -lrt -Wall -Wextra  -o tp1a
./tp1a
```


### c

```
cd TD1/src
g++ main_tp1c.cpp TimeSpec.cpp Signature.cpp -lrt -Wall -Wextra -o td1c
./td1c <nLoops>
``` 

## TD2

### a

```
cd TP2/src
g++ main_tp2a.cpp  -lrt -lpthread -Wall -Wextra -o tp2a
./tp2a <nLoops> <nTasks>
```

### b

```
cd TP2/src
g++ main_tp2b.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o tp2b
./tp2b <nLoops> <nTasks> <useMutex>

./tp2b <nLoops> <nTasks> <useMutex>
exemple:  ./tp2b 10000 3 0
          ./tp2b 10000 3 1
```

## TD3

### b

```
cd TP3/src
g++ main_tp3b.cpp TimeSpec.cpp Timer.cpp CountDown.cpp PeriodicTimer.cpp -lrt -lpthread -Wall -Wextra -o tp3b
./tp3b
```
