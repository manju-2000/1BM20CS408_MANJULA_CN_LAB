#include <iostream>
#include <string.h>

using namespace std;

int crc(char *ip, char *op, char *poly, int mode)
{
    strcpy(op, ip);
    if (mode) {
        for (int i = 1; i < strlen(poly); i++)
            strcat(op, "0");
    cout << "modified input" << op <<endl; 
    }
    for (int i = 0; i < strlen(ip); i++) {
        if (op[i] == '1') {
            for (int j = 0; j < strlen(poly); j++) {
                if (op[i + j] == poly[j])
                    op[i + j] = '0';
                else
                    op[i + j] = '1';
            }
        }
    }
    for (int i = 0; i < strlen(op); i++)
        if (op[i] == '1')
            return 0;
    return 1;
}


int main()
{
    char ip[50], op[50], recv[50];
    char poly[] = "10001000000100001";
    int choice;
    cout << "Enter the input message in binary:";
    cin >> ip;
    cout << "generated polynomial is" << poly <<endl;
    crc(ip, op, poly, 1);
    cout<<"The checksum is:"<<op+strlen(ip)<<endl;
    cout << "The transmitted message is: " << ip << op + strlen(ip) << endl;
    cout << "do you want to test error" << endl;
    cin >> choice;
    if(choice == 1)
    {
    	int pos,n;
    	char cp[50];
    	strcmp(cp, op);
		cout<<"Enter the position where to insert error bit"<<endl;
		cin>>pos;
		cout << "enter bit you wanted to insert" <<endl;
		cin >> n;
		cp[pos]=n;
		if(!strcmp(op, cp))
			{
				cout << "No error"<<endl;
			}
		else
			{
				cout << "Error occured"<<endl;
			}
		return 0;
	}
	else{ cout << ""<<endl;}
    cout << "Enter the recevied message in binary" << endl;
    cin >> recv;
    if (crc(recv, op, poly, 0))
        cout << "No error in data" << endl;
    else
    	
        cout << "Error in data transmission has occurred" << endl;

    return 0;
}
