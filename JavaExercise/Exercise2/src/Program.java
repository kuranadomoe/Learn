import java.util.Scanner;
public class Program
{

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int number = input.nextInt(), high = 0,low = 0;
		boolean judgement = true;//输入个位数默认为true 
		for(;number > 10;)//当number只剩下两位数时high和low刚好进行最后一次比较
		{
			low = number % 10;
			number /= 10;
			high = number % 10;
			if(high < low)//出现高位数小于低位数则将judgment设为false并终止循环
			{
				judgement = false;
				break;
			}
		}
		System.out.println(judgement);
		input.close();
	}

}
