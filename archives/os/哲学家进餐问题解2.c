semaphore chopstick = {1, 1, 1, 1, 1};
semaphore mutex = 1;

void philosopher(int i)
{
	thinking();
	P(mutex);
	P(chopstick[i]);
	P(chopstick[(i+1)%5]);
	V(mutex);

	eating();

	V(chopstick[(i+1)%5])
	V(chopstick[i]);
}
