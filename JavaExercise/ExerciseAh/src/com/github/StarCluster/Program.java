package com.github.StarCluster;

public class Program
{
	
	public static void main(String[] args)
	{
		Numeral num = new Numeral();
		for (int i = 0; i < 10; ++i)
		{
			try
			{
				Thread produce = new Thread()
				{
					public void run()
					{
						num.produce();
					}
				};
				produce.start();
				produce.join();
				Thread consume = new Thread()
				{
					public void run()
					{
						num.consume();
					}
				};
				consume.start();
				consume.join();
			}
			catch (InterruptedException e)
			{
				System.out.println("Interrupted exception!");
			}
		}
		System.out.println("Program runs completed.");
	}
	
}
