/*twoSum*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<(sizeof(nums)/sizeof(nums[0]));++i)
        {
            for(int j=1;j<(sizeof(nums)/sizeof(nums[0]));++j)
                if(((target-nums[i])==nums[j])&&(i!=j)) {res.push_back(i);res.push_back(j);}
        }
        return res;
    }
};

/*Add Two Numbers*/
//一
typedef struct ListNode{
		int val;
		ListNode* next;
}ListNode*;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* res = (ListNode*)malloc(sizeof(ListNode));
ListNode* h = NULL,**t=&h;//h为待返回的结点,*t为移动结点
int x=0,y=0,carry=0,sum=0;//carry:进位控制

/*        vector<int> addArr1;
        vector<int> addArr2;
        while(l1->next!=NULL && l2->next!=NULL)
        {
            addArr1.push(l1->val);
            addArr2.push(l2->val);
        }
        for(int i=0;i<addArr1.size();++i)
        {
            res.insert(addArr1.pop(i)+addArr2.pop(i));
        }
        return res;*/
		while(l1!=NULL ||l2!=NULL)
		{
			x=getValueAndMoveNext(l1);
			y=getValueAndMoveNext(l2);
			sum=x+y+carry;
			ListNode* node = new ListNode(sum%10);//将余数存于链表
			*t=node;
			t=(&node->next);
			carry=sum/10;//是否超过10
		}
		if(carry>0){
			ListNode* node = new ListNode(carry%10);
			*t=node;
		}
		return h;
    }
private:
	int getValueAndMoveNext(ListNode* &l)
	{
		int x=0;
		if(l!=NULL)
		{
			x=l->val;
			l=l->next;
		}
		return x;
	}
};

//二
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
    }
};
/*Add Two Numbers*/

/*longest substring*/

int longestSubstring(char* &str)
{
	int length=1,maxSubString=1,pos=-1;//count=0;
	int i,j;
	for(i=0;i<str.size();++i)
	{
		for(j=i+1;j<str.size()-1;++j)
		{if(str[i]!=str[j]) if(++length>maxSubString) maxSubString=length;
		else {pos=j;length=1;break;}
		}
	}
	printf("pos:%d",pos);
	return maxSubString;
}

void main()
{
	char str[]={'a','b','c','a','b','c','b','b'};
	printf("longest length:%d",longestSubstring(str));
	return 0;
}

/*longest substring*/

