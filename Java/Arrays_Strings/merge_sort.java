package Arrays_Strings;

import java.util.Arrays;

/**
 * 
 * @author Souparni Agnihotri
 *Implementation of merge sort. Runtime O(n logn)
 *mergeSort is a recursive call -> O(logn)
 *and merge function takes O(n) time as it need to merge all of the elements in the array.
 */
public class merge_sort {
	
	public static void mergeSort(int[] a, int l, int r){
		
		if(l < r){
			int mid = (l + r)/2;
			mergeSort(a, l, mid); //all the way up to the midpoint initially
			mergeSort(a, mid + 1, r);
			merge(a, l, mid, r); //this will be called once we get all of the split elements
		}
	}
	
	public static int[] merge(int[] a, int l, int mid, int r){
		
		int[] temparr = new int[a.length];  //keep a temporary buffer array
		
		for (int i = l; i <= r; i++){  //copy all of the elements in the array into temparr
			temparr[i] = a[i];
		}
		/**
		 * i and j help us keep track of our position in our temparr.
		 * k will always start from the position that needs to be replaced in a.
		 */
		int i = l;  
		int j = mid + 1;
		int k = l; //<-- starting position to replace the arr. 
		
		//iterate through and make a comparision to check which element to add. 
		
		while (i <= mid && j <= r){
			if(temparr[i] <= temparr[j]){
				a[k] = temparr[i];
				i++;
			}
			
			else{
				a[k] = temparr[j];
				j++;
			}
			k++;
		}
		//if j > r then just copy the rest of the elements from the left array. 
		while(i <= mid){
			a[k] = temparr[i];
			i++;
			k++;
		}
		//printing
		for (int i1 = 0; i1<a.length; i1++){
			System.out.println(a[i1]);
		}
		return a;
	}

	public static void main(String[] args) {
		int[] arr = { 7, 5, 10, 9, 1 };
		mergeSort(arr, 0, 4);
	}
}
