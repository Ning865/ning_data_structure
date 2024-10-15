#include <iostream>
using namespace std;
#define MiXSIZE 50
typedef struct{
	char data[MiXSIZE];
	int length;
}SqString;
//生成串
void StrAssign(SqString &s,char cstr[]){
	int cnt = 0 ;
	for(cnt=0;cstr[cnt]!='\0';++cnt){
		s.data[cnt]=cstr[cnt];
	}
	s.length = cnt;
}
//销毁串
void DestroyStr(SqString &s){}
//串复制
void StrCopy(SqString &s,SqString t){
	s.length=t.length;
	for(int i=0;i<t.length;++i){
		s.data[i]=t.data[i];
	}
}
//判断串是否相等
bool StrEqual(SqString s,SqString t){
	if(s.length != t.length) return false;
	bool flag = true;
	for(int i=0;i<s.length;++i){
		if(s.data[i]!=t.data[i]){
			flag = false;
			break;
		}
	}
	return flag;
}
//求串的长度
int StrLength(SqString s){
	return s.length;
}
//串拼接
SqString Concat(SqString s,SqString t){
	SqString str;
	str.length = s.length + t.length;
	for(int i=0;i<s.length;++i){
		str.data[i]=s.data[i];
	}
	for(int j=0;j<t.length;++j){
		str.data[j+s.length]=t.data[j];
	}
	return str;
}
//求子串
SqString SubStr(SqString s,int i,int j){
	SqString str;
	if(i<=0 || i+j>=s.length || j<0 || i>s.length)
		return str;
	i-=1;
	for(int l=0;l<j;++l){
		str.data[l]=s.data[i++];
	}
	str.length = j;
	return str;
}
//子串插入
SqString InStr(SqString s1,int i,SqString s2){
	SqString str;
	if(i<=0 || i>s1.length+1)
		return str;
	str.length = s1.length+s2.length;
	int c;
	for(c=0;c<i-1;++c){
		str.data[c]=s1.data[c];
	}
	for(int j=0;j<s2.length;++j,++c){
		str.data[c]=s2.data[j];
	}
	for(int j=i-1;j<s1.length;++j,++c){
		str.data[c] = s1.data[j]; 
	}
	return str;
}
//子串删除
SqString DelStr(SqString s,int i,int j){
	SqString str;
	if(i<=0 || i+j>=s.length )
		return str;
	int c=0;
	for(;c<i-1;++c){
		str.data[c]=s.data[c];
	}
	for(int k=i+j-1;k<s.length;++k,++c){
		str.data[c] = s.data[k];
	}
	str.length=c;
	return str;
}
//子串替换
SqString RepStr(SqString s,int i,int j,SqString t){
	SqString str;
	if(i<=0 || i>s.length || i+j-1 >s.length)
		return str;
	int c=0;
	for(;c<i-1;++c){
		str.data[c]=s.data[c];
	}
	for(int k=0;k<j;++k,++c){
		str.data[c]=t.data[k];
	}
	for(int k=i+j-1;k<s.length;++k,++c){
		str.data[c]=s.data[k];
	}
	str.length = s.length+t.length-j;
	return str;
}
void DispStr(SqString s){
	for(int i=0;i<s.length;i++){
		cout << s.data[i] <<" ";
	}
	cout << endl;
}
void test(){
	char a[5]={'a','b','c','d','e'};
	SqString s1,s2;
	StrAssign(s1,a);
	DispStr(s1);
	cout << StrLength(s1)<<endl;
	StrCopy(s2,s1);
	DispStr(s2);
	cout << StrLength(s2)<<endl;
	if(StrEqual(s1,s2)) cout <<"串相等！"<<endl;
	else cout << "串不等！"<<endl;
	SqString t;
	t=Concat(s1,s2);
	DispStr(t);
	cout << "T: "<<StrLength(t) <<endl;
	SqString s3=SubStr(s1,1,3);
	DispStr(s3);
	cout << "S3: "<<StrLength(s3)<<endl;
	SqString s4=InStr(s2,4,s3);
	DispStr(s4);
	cout << "S4: "<<StrLength(s4)<<endl;
	SqString s5=DelStr(s4,4,3);
	DispStr(s5);
	cout << "S5 : "<<StrLength(s5)<<endl;
	SqString s6=RepStr(s1,2,4,s3);
	DispStr(s6);
	cout << "S6: "<<StrLength(s6);
}

