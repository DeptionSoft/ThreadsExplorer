# ThreadsExplorer
## Threads Explorer is a utility for getting data about threads of a given process. The process can be selected by name or by PID - Processor identification. Information obtained about TID - Thread identification and CycledDelta - cycle counter, which uses the clock cycle counter designed for thread run-time accounting. 

### It used to measure the resource usage of each thread in a given process.

Because many threads run for such a short amount of time that they are seldom (if ever) the currently running thread when the clock interval timer interrupt occurs, they are not charged for much of their CPU time. The total number of clock cycles represents the actual number of processor cycles that each thread in the process accrued. 

***

## Threads Explorer - утилита для получения данных о потоках заданного процесса. Процесс можно выбрать по названию или по PID - Processor identification. Информация получается о TID - Thread identification и CycledDelta - счетчик циклов, предназначенный для учета времени выполнения потоков. 

### Применяется для измерения использования ресусров каждого потока заданного процесса.

Поскольку многие потоки выполняются в течение такого короткого промежутка времени, что они редко (если вообще когда-либо) являются текущим запущенным потоком, когда происходит прерывание таймера тактового интервала, они не загружают большую часть своего процессорного времени. Общее количество тактовых циклов представляет собой фактическое количество циклов процессора, которые накопил каждый поток в процессе.
