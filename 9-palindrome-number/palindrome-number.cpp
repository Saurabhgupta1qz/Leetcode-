class Solution {
public:
    bool isPalindrome(int x) {
//    if(x<0) return false;
//    int origi = x;
//    long long rev = 0;
//    while(x!=0){
//     rev = rev*10+x%10;
//     x = x/10;
//    }
//    if(rev==origi) return true;
//     return false;
if(x<0||(x%10==0&&x!=0)) return false;
int rev = 0;
while(x>rev){
    rev = rev*10+x%10;
    x = x/10;
}
return (x==rev)||(x==(rev/10));
    }
};