package homework2;
import java.io.*;
import java.util.*;

/*class words{
	public String word;
	public String mean;
	public void words(String word,String mean) {
		this.word=word;
		this.mean=mean;
	}
}*/

public class recordEnglish {
	public HashMap<String,String> dictionary=new HashMap<String,String>();
	
	public void putSet() {
		
		
			Scanner sc = new Scanner(System.in);
			
			
			while(true){ 
			
	    	System.out.println("�����뵥�ʣ�");
	    	String word = sc.next();
	    	if (word.equals("exit")) break;
	    	else{
	    		
		    	System.out.println("�����뵥�����壺");
				String mean = sc.next();
				dictionary.put(word,mean);
				System.out.println("�ɹ���ӵ��ʣ�"+word);
		    }
		    
			    
			
			   
			}
			
		try {
			String line = System.getProperty("line.separator");
		    StringBuffer str = new StringBuffer();
		    FileWriter fw = new FileWriter("dictionary.txt", true);
		    Set set = dictionary.entrySet();
		    Iterator iter = set.iterator();
		    while(iter.hasNext()){
		    Map.Entry entry = (Map.Entry)iter.next(); 
		    str.append(entry.getKey()+" : "+entry.getValue()).append(line);
			
		   }
		    
		    fw.write(str.toString());
			fw.close();
		}catch (Exception e) {
			// TODO: handle exception
		}
		
		
	}
	
	public void findWord(){
        Scanner sc = new Scanner(System.in);
		
		while(true){
			System.out.println("��������Ҫ��ѯ�ĵ��ʣ�");
			String word = sc.next();
			String mean = dictionary.get(word);
		    
			if(mean!=null){
				System.out.println(word+"���壺"+mean);
			}
			else{
				System.out.println("�õ��ʲ�����");
			}
			
		   if (sc.next().equals("exit")) break; 
		}
		
	}
	
	public static void main(String[] args) {
		recordEnglish a = new recordEnglish() ;
		a.putSet();
		a.findWord();
	}

	
	

}
