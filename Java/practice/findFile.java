package homework2;

import java.io.*;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class findFile {
	
	String name;
	String path;
	long length;
	String key;
	int count;
	
	
	Map<String,findFile> record = new HashMap<String, findFile>(); 
	
	public findFile(File f){
		name=f.getName();
		length=f.length();
		path = f.getAbsolutePath();
		count=0;
	}
	public findFile(){
		name=null;
		length=0;
		path = null;
		count=0;
	}
	
	public void find(File file) {
		
		File[] list = file.listFiles();
		for(int i=0;i<list.length;i++){
			
			if(list[i].isDirectory()){
				find(list[i]);
			}
			else{
				key=list[i].getName()+list[i].length();
				findFile ss=new findFile(list[i]);
			 if(record.get(key)==null){
				    ss.count=1;
					record.put(key,ss);
				}
				else{
					ss=record.get(key);
					ss.path=ss.path+"\r\t"+list[i].getAbsolutePath();
					record.get(key).count++;	
				}
			}
		}
		
	}

	public void Information() {
		try {
		    Set set = record.entrySet();
		    Iterator iter = set.iterator();
		    boolean flag = true;
		    while(iter.hasNext()){
			    Map.Entry entry = (Map.Entry)iter.next();
			    findFile s1=(findFile)entry.getValue();
			    if(s1.count>1){
			    	System.out.println(s1.name);
			    	System.out.println(s1.path);
			    	flag=false;
			    }
		    }
		    if(flag==true){
		    	System.out.println("无重复文件");
		    }
		    
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f =new File(args[0]);
		findFile file = new findFile();
		file.find(f);
		file.Information();
		
	}
	

}
