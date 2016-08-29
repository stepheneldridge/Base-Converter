#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int log(int b, double x){
	if(x<=1)return 0;
	return floor(log(x)/log(b));
}

int valueOf(char c){
	if(c>=48&&c<=57){
		return (int)(c-48);
	}else if(c>=65&&c<=90){
		return (int)(c-55);
	}else if(c>=97&&c<=122){
		return (int)(c-87);
	}
	return -1;
}

char toValue(int i){
	if(i>=0&&i<=9){
		return char(i+48);
	}else if(i>=10&&i<=35){
		return char(i+55);
	}
	return '?';
}
double toDec(int b, string num){
	int vals[num.length()];
	double number = 0;
	int radix = num.length();
	int i;
	for(i = 0; i<num.length(); i++){
		vals[i] = valueOf(num.at(i));
		if(vals[i]==-1)radix=i;
	}
	for(i = 0; i<num.length(); i++){
		if(i<radix){
			number+=vals[i]*pow(b,radix-i-1);
		}else if(i>radix){
			number+=vals[i]*pow(b,radix-i);
		}
	}
	return number;
}

string toBase(int b, double num){
	string temp = "";
	double value = num;
	int start = log(b,num);
	int i = 0;
	int times;
	double power;
	do{
		power = pow(b,start-i);
		times = (int)floor(value/power);//divide(value,power);
		temp+=toValue(times);
		value-=power*times;
		if(start-i==0&&value>0)temp+=".";
		i++;
	}while((value>0||start-i>=0)&&i<100);
	return temp;
}

int main(){
	string number;
	int start = 10;
	int finish = 10;
	cout.precision(16);
	cout<<"Converts up to base 35"<<endl;
	start:
	cout<<"Starting Base: ";
	cin>>start;
	cout<<endl<<"Ending Base: ";
	cin>>finish;
	cout<<endl<<"Number: ";
	cin>>number;
	double dec = toDec(start,number);
	cout<<endl<<"Input: "<<number<<endl<<"Decimal: "<<dec<<endl<<"Output: "<<toBase(finish,dec)<<endl<<endl;
	goto start;
}

