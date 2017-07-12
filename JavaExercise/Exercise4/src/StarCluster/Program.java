package StarCluster;

public class Program
{

	public static void main(String[] args)
	{
		try 
		{
			Triangle demo1 = new Triangle(3,4,5);
			Triangle demo2 = new Triangle(7,8,9);
			System.out.println("边长为3,4,5的三角形的周长是"+demo1.Circumference()+",面积是"+demo1.Area());
			System.out.println("边长为7,8,9的三角形的周长是"+demo2.Circumference()+",面积是"+demo2.Area());
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

}
