semaphore chopstick = {1, 1, 1, 1, 1};
semaphore eating = 4;

void philosopher(int i)
{
	while(1)
	{
		thinking();

		P(eating);
		P(chopstick[i]);
		P(chopstick[(i + 1)%5]);

		eating();

		V(chopstick[(i + 1)%5]);
		V(chopstick[i]);
		V(eating);
	}
}
