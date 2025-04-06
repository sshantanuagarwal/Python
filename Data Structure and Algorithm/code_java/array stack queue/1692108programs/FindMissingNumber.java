
public class FindMissingNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr={1, 2, 4,6, 3, 7, 8};
		int len=arr.length;
		int sum=(len+1)*(len+2)/2;
		int count=0;
		for(int i=0;i<len;i++){
			sum=sum-arr[i];
		}
		System.out.println("missing number "+(sum-count));
		System.out.println(missing(arr));
	}
	
	public static int  missing(int a[]){
		int x1=a[0];
		int x2=1;
		 for (int i = 1; i< a.length; i++)
		        x1 = x1^a[i];
		 for ( int i = 2; i <= (a.length+1); i++)
		        x2 = x2^i;   
		 return (x1^x2);
	}

}
