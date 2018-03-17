package homework2;

import java.util.EmptyStackException;



public class Line {
	public double length;
	public Line(Point p1,Point p2){
		try{
			length=Math.sqrt(Math.pow((p1.x-p2.x), 2)+Math.pow((p1.y-p2.y), 2));
			if(p1.x==p2.x&&p1.y==p2.y)
				throw new Exception();
		}
		catch (Exception e) {
			// TODO: handle exception
			System.out.println("两点重合，无法确定一条直线");
		}
		System.out.println("产生一条直线，长度为：");
		System.out.println(length);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
         Point p1=new Point(1, 1);
         Point p2=new Point(1, 1);
         Line  l1=new Line(p1, p2); 
         
         String s = "hah";
         long a=1;
         s=s+a;
         System.out.println(s);
         
         try {
			s=args[0];
			for(int i=0;i<s.length();i++){
				if(s.charAt(i)=='\n'){
					System.out.println("huanhang");
					
				}
			}
			System.out.println("length  "+s.length());
			
			
		} catch (Exception e) {
			// TODO: handle exception
			
		}
	}

	

}
