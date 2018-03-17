package homework2;
import java.awt.Frame;
import java.io.*;

import javax.swing.text.AbstractDocument.BranchElement;

public class input {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        //"E:\\WorkSpace\\homework2\\a.txt"
		char [][]a=new char [8][];
		try{
			
			 FileInputStream fr = new FileInputStream(args[0]);
	         InputStreamReader fis =new InputStreamReader(fr,"GBK");
	         BufferedReader br=new BufferedReader(fis);
	         
	         String s = new String();
	         int i=0;
	         while((s=br.readLine())!=null){
	        	a[i++]=s.toCharArray();
	         }
	       br.close();
	       fis.close();
           fr.close();    
		}
		catch (Exception e) {
			// TODO: handle exception
		}
	    
        
	    System.out.println(a[1]);
	    int [] num=new int [47];
	    for(int i=0;i<8;i++){
	    	int k=0;
	    	//计算行
	    	for(int j=0;j<8;j++){
	    		if(a[i][j]=='1'){
	    			k++;
	    		}
	    	}
	    	num[i]=k;
	    	//计算列
	    	k=0;
	    	for(int j=0;j<8;j++){
	    		if(a[j][i]=='1'){
	    			k++;
	    		}
	    	}
	    	num[i+8]=k;
	    	//计算左斜线
	    	int n1=0,n2=i;
	    	k=0;
	    	while (n1!=-1&&n2!=8) {
	    		if(a[n1--][n2++]=='1'){
	    			k++;
	    		}
			}
	    	num[i+16]=k;
	    	
	    	n1=i+1;n2=7;
	    	k=0;
	    	while (n1!=8&&n2!=-1) {
	    		if(a[n1++][n2--]=='1'){
	    			k++;
	    		}
			}
	    	num[i+24]=k;
	    	//计算右斜线
	    	k=n1=0;
	    	n2=i;
	    	while (n1!=8&&n2!=8) {
	    		if(a[n1++][n2++]=='1'){
	    			k++;
	    		}
			}
	    	num[i+31]=k;
	    	
	    	n1=i+1;n2=0;
	    	k=0;
	    	while (n1!=8&&n2!=8) {
	    		if(a[n1++][n2++]=='1'){
	    			k++;
	    		}
			}
	    	num[i+39]=k;
	    	
	    }
	    int k=0;
	    for(int i=0;i<46;i++){
	    	if(num[i]>k)
	    		k=num[i];
	    }
	    System.out.println(k);
	    
	 
}
}