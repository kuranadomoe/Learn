import java.util.Scanner;
public class Program
{

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("请输入摄氏温度C:");
		float C = input.nextFloat(),F = (9.0f/5.0f)*C+32;
		System.out.println("摄氏温度"+C+"°C对应的华氏温度为"+F+"°F");
		input.close();
	}

}