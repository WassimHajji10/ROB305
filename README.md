# ROB305 - TD

Cours : ROB305  ENSTA Paris.

Etudiant : Hajji Wassim

## TD1

### a


```
cd TP1/src
g++  main_tp1a.cpp TimeSpec.cpp -lrt -Wall -Wextra  -o tp1a
./tp1a
```
### b


```
cd TP1/src
g++ main_tp1b.cpp -lrt  -Wall -Wextra -o tp1b
./tp1b
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
### a

```
cd TP3/src
g++ main_tp3a.cpp Chrono.cpp TimeSpec.cpp -lrt  -Wall -Wextra -o tp3a
./tp3a
```

### b

```
cd TP3/src
g++ main_tp3b.cpp TimeSpec.cpp Timer.cpp CountDown.cpp PeriodicTimer.cpp -lrt -lpthread -Wall -Wextra -o tp3b
./tp3b
```

### c

```
cd TP3/src
g++ main_tp3c.cpp Calibrator.cpp TimeSpec.cpp Cpuloop.cpp Looper.cpp Timer.cpp PeriodicTimer.cpp  -lrt  -Wall -Wextra -o tp3c
./tp3c
```

## TD4
### a

```
cd TP4/src
g++ main_tp4a.cpp PosixThread.cpp Thread.cpp Chrono.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td4a
./tp4a <nLoops> <nTasks>
```

### b

```
cd TP4/src
g++ main_tp4b.cpp PosixThread.cpp Thread.cpp Chrono.cpp TimeSpec.cpp Mutex.cpp -lrt -lpthread -Wall -Wextra -o td4b
./tp4b <nLoops> <nTasks>
```

### c

```
cd TP4/src
g++ main_tp4c.cpp PosixThread.cpp Thread.cpp Chrono.cpp SemaPhore.cpp Mutex.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td4c
./td4c <nCons> <nProd>
```

### TD5

```
cd TP5/src
g++ main_tp5.cpp PosixThread.cpp Mutex.cpp ThreadCpuLoop.cpp  Calibrator.cpp TimeSpec.cpp CpuLoop.cpp Looper.cpp Timer.cpp PeriodicTimer.cpp Thread.cpp  -lrt -lpthread  -Wall -Wextra -o tp5
./tp5

```