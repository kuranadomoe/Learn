
public class Main
{

	public static void main(String[] args) 
	{	
		System.out.println("验证3~100之间的数是否符合哥德巴赫猜想：");
		for(int Goldbach = 4; Goldbach <= 100; Goldbach += 2)
		{
			for(int num1 = 2; Goldbach - num1 > 1; ++num1)
				if(MyMath.Prime(num1) && MyMath.Prime(Goldbach - num1))
					System.out.println(Goldbach + " = " + num1 + " + " + (Goldbach - num1));
		}
		System.out.println("输出结束。");
	}

}
