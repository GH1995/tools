semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

void producer()
{
	while(1)
	{
		P(empty);
		P(mutex);
		item = produce_item();
		V(mutex);
		V(full);
	}
}


void consumer()
{
	while(1)
	{
		P(full);
		P(mutex);
		item = remove_item();
		V(mutex);
		V(empty);
		consume_item(item);
	}
}
