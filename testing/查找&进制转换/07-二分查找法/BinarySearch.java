public class BinarySearch{

	public static void main( String[] args ){	
		//二分查找法, 前提数组是  "有序的"
		int[] ary = { -2, 1, 3, 6, 7, 9 };		
		int num = Integer.valueOf( args[0] );
		
		//我要在上面找到 "5"
		int ret = getNum( ary, num );
		
		System.out.println( "ret : "+ ret );	
	}

	public static int getNum( int[] ary, int num ){

		int mid  = ary.length / 2;		
		int left = 0;                //左边
		int right = ary.length - 1;  //右边

		while( left <= right ){
			if( ary[mid]==num ){
				return mid;
			}
			if( ary[mid] > num ){
				right = mid - 1;     //更新 "右"  的值
				System.out.println( "更新 right: "+ right );
			}else if( ary[mid]<num ){
				left  = mid + 1;
				System.out.println( "更新 left: "+ left );
			}
			mid = (left+right)/2;    //产生一个新的中点
			System.out.println( "更新 mid: "+ mid );
		}
		return -1;     //-1 ： 代表没有找到
	}
	


}