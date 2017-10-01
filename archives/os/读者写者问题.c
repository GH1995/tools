semaphore rmutex = 1;
semaphore wmutex = 1;
int readcount = 0;

void reader()
{
	while(1)
	{
		P(rmutex);
		readcount++;
		if(readcount == 0) P(wmutex);
		V(rmutex);

		read_data_base();

		P(rmutex);
		readcount--;
		if(readcount == 0) V(wmutex);
		V(rmutex);

		use_dataread();
	}
}

void writer()
{
	while(1)
	{
		think_up_data();

		P(wmutex);
		write_data_base();
		V(wmutex);
	}
}
