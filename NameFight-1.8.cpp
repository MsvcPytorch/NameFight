#include <string>
#include <bits/stdc++.h>
#include <Windows.h>
//#include <thread>
#define inf 100000 
using namespace std;
string namet1[2560],namet2[2560],name,fseed;
int att1[2560],att2[2560],def1[2560],def2[2560],bld1[2560],bld2[2560],bj1[2560],bj2[2560],tb1[2560],tb2[2560],tbCD1[2560],tbCD2[2560],bjCD1[2560],bjCD2[2560],cure[2][2560],cureCD[2][2560];
int ltn[2][2560],ltnCD[2][2560],ltnh[2][2560];
int rif[2][2560],refCD[2][2560],mir[2][2560];
int sld[2][2560],sldCD[2][2560],sldn[2][2560]; 
int grh[2][2560],grhCD[2][2560];
int spd[2][2560]; 
int cr[256];
int Suoxue,Baotou;
int Gui_or_not; 
int Rinicklife[2][2560];
std::string SHA1(std::string s)
{
    const char HEX_CHAR[]={'0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    const unsigned long K[] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};
    //��չ��K*512λ
    unsigned long *data;
    int l;
    l = s.length()*8;
    data = new unsigned long[((l/512)+1)*512];
    memset(data, 0, sizeof(data[0])*((l/512)+1)*512);
    for(unsigned int i = 0; i < s.length(); ++i){
        data[i / 4] |= s[i] << 8*(3 - (i % 4));
    }
    data[s.length() / 4] |= 0x80 << 8*(3-(s.length()%4));
    data[((l/512)+1)*512/32-1]=l;
    l = (l/512)+1;
    //��ʼ����
    unsigned long H[5], G[5];
    H[0] = G[0] = 0x67452301;
    H[1] = G[1] = 0xEFCDAB89;
    H[2] = G[2] = 0x98BADCFE;
    H[3] = G[3] = 0x10325476;
    H[4] = G[4] = 0xC3D2E1F0;
    for(int i = 0; i<l; ++i){
        unsigned long W[80];
        int t;
        for(t = 0; t<16; ++t)
            W[t] = data[i*16+t];
        for(t = 16; t<80; ++t){
            unsigned long tmp = W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16];
            W[t] = (tmp << 1)|(tmp >> 31);
        }
        unsigned long tmp;
        for(t = 0; t<5; ++t)
            H[t] = G[t];
        for(t = 0; t<20; ++t){
            tmp = ((H[0] << 5) | (H[0] >> 27)) + ((H[1] & H[2]) | (~ H[1] & H[3])) + H[4] + W[t] + K[0];
            H[4] = H[3]; H[3] = H[2]; H[2] = (H[1]<<30)|(H[1] >> 2); H[1] = H[0]; H[0] = tmp;
        }
        for(t = 20; t<40; ++t){
            tmp = ((H[0] << 5) | (H[0] >> 27)) + (H[1] ^ H[2] ^ H[3]) + H[4] + W[t] + K[1];
            H[4] = H[3]; H[3] = H[2]; H[2] = (H[1]<<30)|(H[1] >> 2); H[1] = H[0]; H[0] = tmp;
        }
        for(t = 40; t<60; ++t){
            tmp = ((H[0] << 5) | (H[0] >> 27)) + ((H[1] & H[2])|(H[2] & H[3])|(H[1] & H[3])) + H[4] + W[t] + K[2];
            H[4] = H[3]; H[3] = H[2]; H[2] = (H[1]<<30)|(H[1] >> 2); H[1] = H[0]; H[0] = tmp;
        }
        for(t = 60; t<80; ++t){
            tmp = ((H[0] << 5) | (H[0] >> 27)) + (H[1] ^ H[2] ^ H[3]) + H[4] + W[t] + K[3];
            H[4] = H[3]; H[3] = H[2]; H[2] = (H[1]<<30)|(H[1] >> 2); H[1] = H[0]; H[0] = tmp;
        }
        for(t = 0; t<5; ++t)
            G[t] += H[t];
    }
    delete data;
    char buf[41];
    for(int i = 0; i<40; ++i){
        buf[i] = HEX_CHAR[(G[i / 8] >> (4*(7- (i % 8))))&0xf];
    }
    buf[40] = '\0';
    return std::string(buf);
}
int sx(string s)
{char ans[256];
char res[256]; 
int temp;
int result=0,ansss;
    if (s=="RailGunAttack")
    {return 96;
	}
	else if (s=="RailGunDefend")
	{return 92;
	}
		else if (s=="RailGunSuperattack")
	{return 100;
	}
		else if (s=="RailGunSuperdefend")
	{return 100;
	}
		else if (s=="RailGunBlood")
	{return 200;
	}
	else if (s=="RailGunCure")
	{return 100;
	}
		else if (s=="RailGunLightning")
	{return 100;
	}
	else if (s=="RailGunReflect")
	{return 100;
	}
		else if (s=="RailGunShield")
	{return 100;
	}
		else if (s=="RailGunSpeed")
	{return 100;
	}
		else if (s=="RailGunGroupharm")
	{return 100;
	}
	
	    if (s=="��������Attack")
    {return 66;
	}
	else if (s=="��������Defend")
	{return 66;
	}
		else if (s=="��������Superattack")
	{return 80;
	}
		else if (s=="��������Superdefend")
	{return 80;
	}
		else if (s=="��������Blood")
	{return 66;
	}
	else if (s=="��������Cure")
	{return 80;
	}
		else if (s=="��������Lightning")
	{return 80;
	}
	else if (s=="��������Reflect")
	{return 80;
	}
		else if (s=="��������Shield")
	{return 80;
	}
		else if (s=="��������Groupharm")
	{return 80;
	}
		else if (s=="��������Speed")
	{return 80;
	}
	
	
		    if (s=="littleponyAttack")
    {return 50;
	}
	else if (s=="littleponyDefend")
	{return 50;
	}
		else if (s=="littleponySuperattack")
	{return 50;
	}
		else if (s=="littleponySuperdefend")
	{return 50;
	}
		else if (s=="littleponyBlood")
	{return 44;
	}
	else if (s=="littleponyCure")
	{return 50;
	}
	else if (s=="littleponyLightning")
	{return 30;
	}
		else if (s=="littleponyReflect")
	{return 30;
	}
     	else if (s=="littleponySpeed")
	{return 50;
	}
		else if (s=="littleponyShield")
	{return 30;
	}
		else if (s=="littleponyGroupharm")
	{return 30;
	}
	
	
			    if (s=="�ұ�Attack")
    {return 120;
	}
	else if (s=="�ұ�Defend")
	{return 120;
	}
		else if (s=="�ұ�Superattack")
	{return 100;
	}
		else if (s=="�ұ�Superdefend")
	{return 100;
	}
		else if (s=="�ұ�Blood")
	{return 100; 
	}
	else if (s=="�ұ�Cure")
	{return 100;
	}
	else if (s=="�ұ�Lightning")
	{return 100;
	}
		else if (s=="�ұ�Reflect")
	{return 100;
	}
     	else if (s=="�ұ�Speed")
	{return 100;
	}
		else if (s=="�ұ�Shield")
	{return 100;
	}
		else if (s=="�ұ�Groupharm")
	{return 100;
	}
	
	
				    if (s=="RinickAttack")
    {return 256;
	}
	else if (s=="RinickDefend")
	{return 128;
	}
		else if (s=="RinickSuperattack")
	{return 100;
	}
		else if (s=="RinickSuperdefend")
	{return 100;
	}
		else if (s=="RinickBlood")
	{return 512; 
	}
	else if (s=="RinickCure")
	{return 100;
	}
	else if (s=="RinickLightning")
	{return 100;
	}
		else if (s=="RinickReflect")
	{return 100;
	}
     	else if (s=="RinickSpeed")
	{return 128;
	}
		else if (s=="RinickShield")
	{return 100;
	}
		else if (s=="RinickGroupharm")
	{return 100;
	}
        strcpy(ans,SHA1(SHA1(SHA1(s))).c_str());
       // cout<<ans<<endl;
        //puts(ans);
        //cout<<ans[0];
        //cout<<ans.length()<<endl;
         for (temp=0;temp<=strlen(ans);temp++)
        {
        
		
		if ('A'<=ans[temp] && ans[temp]<='z')
        {if (temp!=0)
        {
		
		//cout<<"jump";
		if (res[temp-1]<9)
		{
		
		res[temp]=res[temp-1]+1;
		//cout<<res[temp]; 
		}
		else
		{res[temp]='0';
		}
	}
	else
	{res[temp]='6';
	}
	}
		
		else
		{
		    res[temp]=ans[temp];
			//cout<<res[temp];
		}
		//cout<<temp<<endl;
		
		}
		//puts(res);
		//cout<<strlen(res)<<endl;
		for (int temp2=0;temp2<=strlen(res)-1;temp2++)
		{result=result+res[temp2]-'0';
		}
		
		//cout<<s<<endl;
	//	puts(res);
//	cout<<result<<endl;
		ansss=result%100;
		
		if (s.substr(0,4)=="test" )
		{if (ansss<=70)
		{return ansss+30;
		}
		else
		{return 100;
		}
		}
		return ansss;
		
}
string operator+(string &content, int number) {

	string temp = "";

	char t = 0;

	while (true) {

		t = number % 10 + '0';

		temp = t + temp;

		number /= 10;

		if (number == 0) {

			return content + temp;

		}

	}

}

//����+=�����+�ţ����� += ����д�� + �����غ���

string&  operator+=(string &content, int number) {

	return content = content + number;

}

int Superattack(int team,int player,int tpl)
{

if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�޸�����Ϸ���룬����������Ϊ����"<<endl; 
att1[player]=inf;
return 0;
 
}
else if (namet1[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�ٻ���һƥС���"<<endl;
namet1[tpl+1]="littlepony";

att1[tpl+1]=sx(namet1[tpl+1]+"Attack");
   def1[tpl+1]=sx(namet1[tpl+1]+"Defend");
  bld1[tpl+1]=sx(namet1[tpl+1]+"Blood")*3;
  bj1[tpl+1]=sx(namet1[tpl+1]+"Superattack");
  tb1[tpl+1]=sx(namet1[tpl+1]+"Superdefend");
  cure[1][tpl+1]=sx(namet1[tpl+1]+"Cure");
  ltn[1][tpl+1]=sx(namet1[tpl+1]+"Lightning");
  rif[1][tpl+1]=sx(namet1[tpl+1]+"Reflect");
  sld[1][tpl+1]=sx(namet1[tpl+1]+"Shield");
  grh[1][tpl+1]=sx(namet1[tpl+1]+"Groupharm");
  spd[1][tpl+1]=sx(namet1[tpl+1]+"Speed");
 // cout<<t1p<<endl;
  return 0; 
}
att1[player]=att1[player]*2;
cout<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"����������������"<<endl;
bjCD1[player]=1;
}
else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�޸�����Ϸ���룬����������Ϊ����"<<endl;
att2[player]=inf;
return 0;
 
}
else if (namet2[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�ٻ���һƥС���"<<endl;
namet2[tpl+1]="littlepony";

att2[tpl+1]=sx(namet2[tpl+1]+"Attack");
   def2[tpl+1]=sx(namet2[tpl+1]+"Defend");
  bld2[tpl+1]=sx(namet2[tpl+1]+"Blood")*3;
  bj2[tpl+1]=sx(namet2[tpl+1]+"Superattack");
  tb2[tpl+1]=sx(namet2[tpl+1]+"Superdefend");
  cure[2][tpl+1]=sx(namet2[tpl+1]+"Cure");
    ltn[2][tpl+1]=sx(namet1[tpl+1]+"Lightning");
  rif[2][tpl+1]=sx(namet1[tpl+1]+"Reflect");
  sld[2][tpl+1]=sx(namet1[tpl+1]+"Shield");
  grh[2][tpl+1]=sx(namet1[tpl+1]+"Groupharm");
  spd[2][tpl+1]=sx(namet1[tpl+1]+"Speed");
  // cout<<t2p<<endl;
  return 0; 
}
att2[player]=att2[player]*2;
cout<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"����������������"<<endl; 
bjCD2[player]=1;
}
}
int Superdefend(int team1,int player1,int tpl)
{if (team1==1)
{if (namet1[player1]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld1[player1]<<")"<<"�޸�����Ϸ���룬�����������Ϊ����"<<endl;
def1[player1]=inf;
return 0;
}
else if (namet1[player1]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player1]<<")"<<"ʹ��С��ƥ��������ǿ������,������������50�������ָ�70"<<endl;
def1[player1]= def1[player1]+50;
att1[player1]= att1[player1]+50;
bld1[player1]= bld1[player1]+70;
return 0; 
}
def1[player1]=def1[player1]*2;
cout<<namet1[player1]<<"(Ѫ��Ϊ"<<bld1[player1]<<")"<<"�������ڷ���������"<<endl;
tbCD1[player1]=1;
}
else
{if (namet2[player1]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld2[player1]<<")"<<"�޸�����Ϸ���룬�����������Ϊ����"<<endl;
def2[player1]=inf;
return 0;
}
else if (namet2[player1]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld2[player1]<<")"<<"ʹ��С��ƥ��������ǿ������,������������50�������ָ�70"<<endl;
def2[player1]= def2[player1]+50;
att2[player1]= att2[player1]+50;
bld2[player1]= bld2[player1]+70;
return 0; 
}
def2[player1]=def2[player1]*2;
cout<<namet2[player1]<<"(Ѫ��Ϊ"<<bld2[player1]<<")"<<"�������ڷ���������"<<endl;
bjCD2[player1]=1;
}
}

int Cure(int team,int player,int tpl)
{int btemp;
cureCD[team][player]=2;
if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�޸�����Ϸ���룬�����Ѫ100��"<<endl;
bld1[player]=bld1[player]+100;
return 0;
}
else if (namet1[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"������С����ǻ�Ѫ20��"<<endl; 
 for (btemp=1;btemp<=tpl;btemp++)
{if (namet1[btemp]=="littlepony")
{

bld1[btemp]=bld1[btemp]+20;
}
}
return 0; 
}
cout<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"Ϊȫ�ӻ�Ѫ"<<att1[player]/tpl<<"��"<<endl;
for (btemp=1;btemp<=tpl;btemp++)
{if (bld1[btemp]>0 && bld1[btemp]<=500)
{ 
bld1[btemp]=bld1[btemp]+att1[player]/tpl;
} 
}

}
else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�޸�����Ϸ���룬�����Ѫ100��"<<endl;
bld2[player]=bld2[player]+100;
return 0;
}
else if (namet2[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"������С����ǻ�Ѫ20��"<<endl;
 for (btemp=1;btemp<=tpl;btemp++)
{if (namet2[btemp]=="littlepony")
{

bld2[btemp]=bld2[btemp]+20;
}
}
return 0; 
}
cout<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"Ϊȫ�ӻ�Ѫ"<<att2[player]/tpl<<"��"<<endl;
for (int btemp=1;btemp<=tpl;btemp++)
{if (bld2[btemp]>0 && bld2[btemp]<=500)
{

bld2[btemp]=bld2[btemp]+att2[player]/tpl;
}
}
}
}
int lightning (int team,int player,int kill)
{ltnCD[team][player]=2;
if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"ʹ�����������������������������׵�ͽ�"<<endl;
ltnh[2][kill]=1;
ltnh[2][kill+1]=1;
if (kill>1)
{ltnh[2][kill-1]=1;
}
att1[player]=att1[player]*3;
return 0;
}
else if (namet1[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�ٻ��׵�С���Զ��ֽ��������˺��Ƽ׹���"<<endl;
att1[player]=(att1[player]+2*def2[kill]/3)*2;
ltnh[2][kill]=1;
return 0;
}
cout<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�ٻ����׶Զ��ֽ����Ƽ׹���"<<endl;
att1[player]=att1[player]+2*def2[kill]/3;
ltnh[2][kill]=1;
}



else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"ʹ�����������������������������׵�ͽ�"<<endl;
ltnh[1][kill]=1;
ltnh[1][kill+1]=1;
if (kill>1)
{ltnh[1][kill-1]=1;
}
att2[player]=att2[player]*3;
return 0;
}
else if (namet2[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�ٻ��׵�С���Զ��ֽ��������˺��Ƽ׹���"<<endl;
att2[player]=(att2[player]+2*def1[kill]/3)*2;
ltnh[1][kill]=1;
return 0;
}
cout<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�ٻ����׶Զ��ֽ����Ƽ׹���"<<endl;
att2[player]=att2[player]+2*def1[kill]/3;
ltnh[1][kill]=1;
}
}


int harm(int team,int player,int destroy,int team1p,int team2p,int harmer)
{int gtemp,l;
if (team==1)
{if (namet1[player]=="�ұ�" && Suoxue==1 )
if (namet2[harmer]=="RailGun")
{cout<<"RailGun�����˹ұ�"<<"("<<"Ѫ��Ϊ"<<bld1[player]<<")"<<"��ͼ��Ѫ���Ʋ�����"<<endl;
Suoxue=0;
if (bld1[player]>destroy)
{cout<<"����Ѫ����Ϊ1"<<endl;
bld1[player]=1;
return 0;
}
else
{Suoxue=0;
return harm(1,player,destroy,team1p,team2p,harmer);
}
}
else
{cout<<namet2[harmer]<<"(Ѫ��Ϊ"<<bld2[harmer]<<")"<<"��"<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"���"<<destroy<<"���˺�"<<endl;
Suoxue=0;
cout<<"�ұƷ�����Ѫ�ң�������ֻ���۳�һ��Ѫ"<<endl;
return harm(1,player,1,team1p,team2p,harmer);
}


if (namet2[harmer]=="�ұ�" && Baotou==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun���ֹұ�"<<"("<<"Ѫ��Ϊ"<<bld2[harmer]<<")"<<"��ͼʹ�ñ�ͷ�Ҳ��Ʋ�����������Ѫ����Ϊ1"<<endl ;
bld2[harmer]=1;
Baotou=0;
return 0;
 }
 else
 {cout<<"�ұ�ʹ�ñ�ͷ�ң��ԶԷ������10���˺�"<<endl;
 Baotou=0;
 return harm(1,player,destroy*10,team1p,team2p,harmer);
  } 
}
}

if (team==2)
{if (namet2[player]=="�ұ�" && Suoxue==1 )
if (namet1[harmer]=="RailGun")
{cout<<"RailGun�����˹ұ�"<<"("<<"Ѫ��Ϊ"<<bld2[player]<<")"<<"��ͼ��Ѫ���Ʋ�����"<<endl;
Suoxue=0;
if (bld2[player]>destroy)
{cout<<"����Ѫ����Ϊ1"<<endl;
bld2[player]=1;
return 0;
}
else
{Suoxue=0;
return harm(2,player,destroy,team1p,team2p,harmer);
}
}
else
{cout<<namet1[harmer]<<"(Ѫ��Ϊ"<<bld1[harmer]<<")"<<"��"<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"���"<<destroy<<"���˺�"<<endl;
Suoxue=0;
cout<<"�ұƷ�����Ѫ�ң�������ֻ���۳�һ��Ѫ"<<endl;
return harm(2,player,1,team1p,team2p,harmer);
}


if (namet1[harmer]=="�ұ�" && Baotou==1)
{if (namet2[player]=="RailGun")
{cout<<"RailGun���ֹұ�"<<"("<<"Ѫ��Ϊ"<<bld1[harmer]<<")"<<"��ͼʹ�ñ�ͷ�Ҳ��Ʋ�����������Ѫ����Ϊ1"<<endl ;
bld1[harmer]=1;
Baotou=0;
return 0;
 }
 else
 {cout<<"�ұ�ʹ�ñ�ͷ�ң��ԶԷ������10���˺�"<<endl;
 Baotou=0;
 return harm(2,player,destroy*10,team1p,team2p,harmer);
  } 
}
}

if (team==1)
{cout<<namet2[harmer]<<"(Ѫ��Ϊ"<<bld2[harmer]<<")"<<"��"<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"���"<<destroy<<"���˺�"<<endl;
 
if (sldn[1][player]!=0)
{
if (sldn[1][player]>=destroy)
{cout<<namet1[player]<<"ʹ����Ѫħ��������"<<destroy<<"���˺�"<<endl;
bld1[player]=bld1[player]+destroy; 
sldn[1][player]=sldn[1][player]-destroy;
if (sldn[1][player]<=0)
{cout<<"������Ѫ��������";
}
return 0;
}
else 
{l=sldn[1][player];
cout<<namet1[player]<<"ʹ����Ѫħ��������"<<sldn[1][player]<<"���˺�"<<endl;
cout<<"������Ѫ��������"<<endl;
bld1[player]=bld1[player]+l; 
sldn[1][player]=0;
return harm(1,player,destroy-l,team1p,team2p,harmer);
}
}
if (bld1[player]>destroy)
  {bld1[player]=bld1[player]-destroy;
  return 0;
  }
  else
  {if (namet1[player]=="Rinick"&&Rinicklife[1][player]>0)
  {cout<<"Rinick����ɱ�ˣ��k��ʣ"<<Rinicklife[1][player]-1<<"����"<<endl;
  cout<<"�k�������ĳ�ʼ����Ϊ"<<1536-(4-Rinicklife[1][player])*500<<endl;
  Rinicklife[1][player]--;
  bld1[player]=1536-(3-Rinicklife[1][player])*500;
  return 0;
  }
  cout<<namet1[player]<<"����ɱ��"<<endl ;
  bld1[player]=bld1[player]-destroy;
  	  	  for (gtemp=player;gtemp<=team1p;gtemp++)
	  {
	  namet1[gtemp]=namet1[gtemp+1];
	  att1[gtemp]=att1[gtemp+1];
	   def1[gtemp]=def1[gtemp+1];
	    bj1[gtemp]=bj1[gtemp+1];
	     tb1[gtemp]=tb1[gtemp+1];
	      tbCD1[gtemp]=tbCD1[gtemp+1];
	       bjCD1[gtemp]=bjCD1[gtemp+1];
	        bld1[gtemp]=bld1[gtemp+1];
	        cure[1][gtemp]=cure[1][gtemp+1];
	        cureCD[1][gtemp]=cureCD[1][gtemp+1];
	        ltn[1][gtemp]=ltn[1][gtemp+1];
	        ltnCD[1][gtemp]=ltnCD[1][gtemp+1];
	        ltnh[1][gtemp]=ltnh[1][gtemp+1];
	           sld[1][gtemp]=sld[1][gtemp+1];
	        sldCD[1][gtemp]=sldCD[1][gtemp+1];
	        sldn[1][gtemp]=sldn[1][gtemp+1];
	        grh[1][gtemp]=grh[1][gtemp+1];
	        grhCD[1][gtemp]=grhCD[1][gtemp+1];
	        spd[1][gtemp]=spd[1][gtemp+1];
	       
	  }
	  return 1;
  }
}

if (team==2)
{cout<<namet1[harmer]<<"(Ѫ��Ϊ"<<bld1[harmer]<<")"<<"��"<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"���"<<destroy<<"���˺�"<<endl;
if (sldn[2][player]!=0)
{
if (sldn[2][player]>=destroy)
{cout<<namet2[player]<<"ʹ����Ѫħ��������"<<destroy<<"���˺�"<<endl;
bld2[player]=bld2[player]+destroy; 
sldn[2][player]=sldn[2][player]-destroy;
if (sldn[2][player]<=0)
{cout<<"������Ѫ��������";
}
return 0;
}
else 
{l=sldn[2][player];
cout<<namet2[player]<<"ʹ����Ѫħ��������"<<sldn[2][player]<<"���˺�"<<endl;
cout<<"������Ѫ��������"<<endl;
bld2[player]=bld2[player]+l; 
sldn[2][player]=0;
return harm(2,player,destroy-l,team1p,team2p,harmer);
}
}
if (bld2[player]>destroy)
  {bld2[player]=bld2[player]-destroy;
  return 0;
  }
  else
  {if (namet2[player]=="Rinick"&&Rinicklife[2][player]>0)
  {cout<<"Rinick����ɱ�ˣ��k��ʣ"<<Rinicklife[2][player]-1<<"����"<<endl;
  cout<<"�k�������ĳ�ʼ����Ϊ"<<1536-(4-Rinicklife[2][player])*500<<endl;
  Rinicklife[2][player]--;
  bld2[player]=1536-(3-Rinicklife[2][player])*500;
  return 0;
  }
  cout<<namet2[player]<<"����ɱ��"<<endl ;
  bld2[player]=bld2[player]-destroy;
   for (gtemp=player;gtemp<=team2p;gtemp++)
	  {
	  namet2[gtemp]=namet2[gtemp+1];
	  att2[gtemp]=att2[gtemp+1];
	   def2[gtemp]=def2[gtemp+1];
	    bj2[gtemp]=bj2[gtemp+1];
	     tb2[gtemp]=tb2[gtemp+1];
	      tbCD2[gtemp]=tbCD2[gtemp+1];
	       bjCD2[gtemp]=bjCD2[gtemp+1];
	        bld2[gtemp]=bld2[gtemp+1];
	          cure[2][gtemp]=cure[2][gtemp+1];
	        cureCD[2][gtemp]=cureCD[2][gtemp+1];
	        ltn[2][gtemp]=ltn[2][gtemp+1];
	        ltnCD[2][gtemp]=ltnCD[2][gtemp+1];
	        ltnh[2][gtemp]=ltnh[2][gtemp+1];
	        sld[2][gtemp]=sld[2][gtemp+1];
	        sldCD[2][gtemp]=sldCD[2][gtemp+1];
	        sldn[2][gtemp]=sldn[2][gtemp+1];
	        grh[2][gtemp]=grh[2][gtemp+1];
	        grhCD[2][gtemp]=grhCD[2][gtemp+1];
	        spd[2][gtemp]=spd[2][gtemp+1];
	       
	       
	  }
	   return 1;
  }
}




 }
 int Shield(int team,int player)
 {sldCD[team][player]=2;
  if (team==1)
  {sldn[1][player]=att1[player]/2;
  cout<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"Ϊ�Լ������"<<att1[player]/2<<"����Ѫ��"<<endl;
  }
   if (team==2)
  {sldn[2][player]=att2[player]/2;
  cout<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"Ϊ�Լ������"<<att2[player]/2<<"����Ѫ��"<<endl;
  }
  } 
int writefile(int team1num,int team2num)
{freopen("input.txt","w",stdout);
int tempo;
cout<<team1num+team2num<<endl;
for (tempo=1;tempo<=team1num;tempo++)
{cout<<namet1[tempo]<<" "<<att1[tempo]<<" "<<def1[tempo]<<" "<<spd[1][tempo]<<" "<<bld1[tempo]<<" "<<sx(namet1[tempo]+"Blood")*3<<endl;
}
for (tempo=1;tempo<=team2num;tempo++)
{cout<<namet2[tempo]<<" "<<att2[tempo]<<" "<<def2[tempo]<<" "<<spd[2][tempo]<<" "<<bld2[tempo]<<" "<<sx(namet2[tempo]+"Blood")*3<<endl;
}
cout<<"temp";
freopen("CON","w",stdout);
}

int reflect(int team,int player,int ournum,int opponum)
{int horsenum; 

if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"�޸��˴��룬������һ�غ������˺�"<<endl;
mir[1][player]=mir[1][player]+opponum;
return 0;
}
else if (namet1[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"��������С��";
for (int btemp=1;btemp<=ournum;btemp++)
{

if (namet1[btemp]=="littlepony" && bld1[btemp]>=60)
{bld1[btemp]=bld1[btemp]-60;
horsenum++;
 }
}
cout<<horsenum<<"ƥ��ÿ�����60������Ϊ�Լ�����"<<horsenum<<"������"<<endl;
mir[1][player]=mir[1][player]+horsenum; 
return 0;
}
cout<<namet1[player]<<"(Ѫ��Ϊ"<<bld1[player]<<")"<<"Ϊ�Լ�������һ�ط�����"<<endl;
}

else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"�޸��˴��룬������һ�غ������˺�"<<endl;
mir[2][player]=mir[2][player]+opponum;
return 0;
}
else if (namet2[player]=="��������")
{cout<<"��������"<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"��������С��";
for (int btemp=1;btemp<=ournum;btemp++)
{

if (namet2[btemp]=="littlepony" && bld2[btemp]>=60)
{bld2[btemp]=bld2[btemp]-60;
horsenum++;
 }
}
cout<<horsenum<<"ƥ��ÿ�����60������Ϊ�Լ�����"<<horsenum<<"������"<<endl;
mir[2][player]=mir[2][player]+horsenum; 
return 0;
}
cout<<namet2[player]<<"(Ѫ��Ϊ"<<bld2[player]<<")"<<"Ϊ�Լ�������һ�ط�����"<<endl;
}



mir[team][player]++;
refCD[team][player]=3;

}



int fight(int t1n,int t2n,string seed,int delay)//namet1,namet2,att,def,bld,bj,tb,cure,cureCD,ltn,ltnCD,ltnh,rif,refCD,mir,sld,sldCD,sldn,grh,grhCD,spd
   {int ytemp,random,target,random1,ntemp,random2,random3;
   string round="1";
   string cuo="1";
   string h;

   for (ytemp=1;ytemp<=t1n;ytemp++)
   {att1[ytemp]=sx(namet1[ytemp]+"Attack");
   def1[ytemp]=sx(namet1[ytemp]+"Defend");
  bld1[ytemp]=sx(namet1[ytemp]+"Blood")*3;
  bj1[ytemp]=sx(namet1[ytemp]+"Superattack");
  tb1[ytemp]=sx(namet1[ytemp]+"Superdefend");
  cure[1][ytemp]=sx(namet1[ytemp]+"Cure");
  ltn[1][ytemp]=sx(namet1[ytemp]+"Lightning");
  rif[1][ytemp]=sx(namet1[ytemp]+"Reflect");
  sld[1][ytemp]=sx(namet1[ytemp]+"Shield");
  grh[1][ytemp]=sx(namet1[ytemp]+"Groupharm");
  spd[1][ytemp]=sx(namet1[ytemp]+"Speed");
  mir[1][ytemp]=0;
  bjCD1[ytemp]=0;
  tbCD1[ytemp]=0;
  cureCD[1][ytemp]=0;
  ltnCD[1][ytemp]=0;
  ltnh[1][ytemp]=0;
  sldCD[1][ytemp]=0;
  sldn[1][ytemp]=0;
  Rinicklife[1][ytemp]=3;
  h=h+namet1[ytemp];
   }
   h=h+"vs";
   for (ytemp=1;ytemp<=t2n;ytemp++)
   {att2[ytemp]=sx(namet2[ytemp]+"Attack");
   def2[ytemp]=sx(namet2[ytemp]+"Defend");
  bld2[ytemp]=sx(namet2[ytemp]+"Blood")*3;
  bj2[ytemp]=sx(namet2[ytemp]+"Superattack");
  tb2[ytemp]=sx(namet2[ytemp]+"Superdefend");
  cure[2][ytemp]=sx(namet2[ytemp]+"Cure");
  ltn[2][ytemp]=sx(namet2[ytemp]+"Lightning");
  rif[2][ytemp]=sx(namet2[ytemp]+"Reflect");
  sld[2][ytemp]=sx(namet2[ytemp]+"Shield");
   grh[2][ytemp]=sx(namet2[ytemp]+"Groupharm");
   spd[2][ytemp]=sx(namet2[ytemp]+"Speed");
  mir[2][ytemp]=0;
    bjCD2[ytemp]=0;
  tbCD2[ytemp]=0;
  cureCD[2][ytemp]=0;
  ltnCD[2][ytemp]=0;
  ltnh[2][ytemp]=0;
  sldCD[2][ytemp]=0;
  sldn[2][ytemp]=0;
  Rinicklife[2][ytemp]=3;
  h=h+namet2[ytemp];
   }
      
     
  if (Gui_or_not==1)
  {writefile(t1n,t2n);
  }
    Suoxue=0;
    Baotou=0;
    
//random3=random1=sx(h+"round"+round+"KaiGua"+seed)%4+1;
  // WinExec("connect.exe",SW_SHOWMAXIMIZED);
   //cout<<"a";
   while(true)
   {if (round.length()>=500)
   {cout<<"�غϹ����Զ��˳�"<<endl;
   return 3;
   }
   
   //cout<<t1n<<" "<<t2n;
   random1=sx(h+"round"+round+"1"+"Magic"+seed)%4+1;
   if (random1==1)
   {cout<<"��һ�Ӱڳ����ɷ���ȫ�ӹ�������25"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {att1[ntemp]=att1[ntemp]+25;
   }
   }
   else if (random1==2)
   {cout<<"��һ�Ӱڳ���ʯ����ȫ�ӷ�������25"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {def1[ntemp]=def1[ntemp]+25;
   }
   }
    else if (random1==3)
   {cout<<"��һ�Ӱڳ�Ӱ�編��ȫ���ٶȼ�40"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {spd[1][ntemp]=spd[1][ntemp]+40;
   }
   }
      else if (random1==4)
   {cout<<"��һ�Ӱڳ���������ȫ��ȫ���Լ�10"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {def1[ntemp]=def1[ntemp]+10;
   att1[ntemp]=att1[ntemp]+10;
   spd[1][ntemp]=spd[1][ntemp]+10;
   }
   }
   
   for (ytemp=1;ytemp<=t1n;ytemp++)
   {
   
   bjCD1[ytemp]--;
   tbCD1[ytemp]--;
   cureCD[1][ytemp]--;
   ltnCD[1][ytemp]--; 
   refCD[1][ytemp]--;
  sldCD[1][ytemp]--;
  grhCD[1][ytemp]--;
   if (bld1[ytemp]>0)
      {if (ltnh[1][ytemp]==0)
      {
	  guabi1:if (namet1[ytemp]=="�ұ�")
      {random3=sx(h+"round"+round+"KaiGua"+seed)%4+1;
      if (random3==1)
      {cout<<"�ұƴ�����Ѫ��"<<endl;
      Suoxue=1;
	  }
	  else if (random3==2)
	  {cout<<"�ұƴ��˱�ͷ��" <<endl;
	  Baotou=1;
	  }
	  else
	  {cout<<"�ұ���غ�û�п���"<<endl;
	  }
}
	   
	  round=round+"1";
	  random=sx(h+"round"+round+namet1[ytemp]+"Choice"+seed)*7;
      target=sx(h+"round"+round+namet1[ytemp]+"Target"+seed)%t2n+1;
	  b:if (random<=bj1[ytemp]&&bjCD1[ytemp]<=0)
      {if (namet1[ytemp]=="Rinick")
      {cout<<"Rinickʹ������������ɱ֮��,"<<namet2[target]<<"��ǿ�л�ɱ"<<endl;
      if (bld1[ytemp]>=bld2[target]*2/3)
      {cout<<"Rinick������ʧ��"<<bld2[target]*2/3<<"��Ѫ "<<endl;
      bld1[ytemp]=bld1[ytemp]-bld2[target]*2/3;
	  }
	  else
	  {cout<<"Rinick��������ֻʣ��һ��Ѫ"<<endl;
	  bld1[ytemp]=1;
	  }
	t2n=t2n-harm(2,target,inf*100,t1n,t2n,ytemp);
	goto l;
	  }
	  
	  
	  Superattack(1,ytemp,t1n);
      if (namet1[ytemp]=="��������")
      {t1n++;
	  }
	  }
	  else if (random>100 && random<=tb1[ytemp]+100 && tbCD1[ytemp]<=0)
	  {if (namet1[ytemp]=="Rinick")
	  {cout<<"Rinick������NULLֵ����"<<endl;
	  cout<<"�Է����з����ܣ���Ѫ��ȫ���ԶԷ��Լ���ɵ����˺���Ϊ�Լ���Ѫ"<<endl;
	  for (int ftemp=1;ftemp<=t2n;ftemp++)
	  {t2n=t2n-harm(2,ftemp,mir[2][ftemp]*50,t1n,t2n,ytemp);
	  t2n=t2n-harm(2,ftemp,sldn[2][ftemp]*2,t1n,t2n,ytemp);
	  bld1[ytemp]=bld1[ytemp]+mir[2][ftemp]*50;
	  bld1[ytemp]=bld1[ytemp]+sldn[2][ftemp]*2;
	   }
	   goto l; 
	  }
	  Superdefend(1,ytemp,t1n);
	  }
	  else if (random>200 && random<=cure[1][ytemp]+200 && cureCD[1][ytemp]<=0)
	  {Cure(1,ytemp,t1n);
	  }
	  else if (random>300 && random<=ltn[1][ytemp]+300 && ltnCD[1][ytemp]<=0)
	  {if (namet1[ytemp]=="Rinick")
      {cout<<"Rinick���õk������ʹ�������,";
      cout<<"���ֵĹ�����Ѫ��ϴ��"<<endl;
      for (int itemp=1;itemp<=t2n;itemp++)
      {att2[itemp]=sx(h+"round"+round+"Rinick"+"Attack"+seed);
      if (sx(h+"round"+round+"Rinick"+"Blood"+seed)*3>=bld2[itemp])
      {
	  }
	  else
	  {
      bld2[itemp]=sx(h+"round"+round+"Rinick"+"Blood"+seed)*3;
	  }
	  def2[itemp]=sx(h+"round"+round+"Rinick"+"Defend"+seed);
      spd[2][itemp]=sx(h+"round"+round+"Rinick"+"Speed"+seed);
	  }
	  goto l;
	  }
	  lightning(1,ytemp,target);
	  }
	  else if (random>400 && random<=rif[1][ytemp]+400 && refCD[1][ytemp]<=0)
	  {reflect(1,ytemp,t1n,t2n);
	  }
	   else if (random>500 && random<=sld[1][ytemp]+500 && sldCD[1][ytemp]<=0)
	  {if (namet1[ytemp]=="Rinick")
	  {if (bld1[ytemp]<=900)
	  {
	  
	  cout<<"Rinick��ʱ���м�ȡ������������ʧѪ��һ���ֻ�Ϊ��Ѫ��"<<endl;
	  cout<<"Rinick�����"<<(1536-bld1[ytemp])/6<<"����Ѫ��" <<endl;
	  sldn[1][ytemp]=sldn[1][ytemp]+(1536-bld1[ytemp])/6;
}
else
{cout<<"Rinick�ӿռ��м�ȡ������������Ѫ��һ���ֻ�Ϊ��Ѫ��"<<endl;
cout<<"Rinick�����"<<bld1[ytemp]/6<<"����Ѫ��"<<endl;
sldn[1][ytemp]=sldn[1][ytemp]+bld1[ytemp]/6;
}
	  goto l;
	  }
	  Shield(1,ytemp);
	  }
	  else if (random>600 && random<=grh[1][ytemp]+600 && grhCD[1][ytemp]<=0)
	  {grhCD[1][ytemp]=4;
	  cout<<namet1[ytemp]<<"������ɨ֮��,�ԶԷ�ȫ�����"<<att1[ytemp]/2<<"���˺�"<<endl;
	  for (int atemp=1;atemp<=t2n;atemp++)
	  {t2n=t2n-harm(2,atemp,att1[ytemp]/2,t1n,t2n,ytemp);
	  if (t2n==0)
	  {return 1;
	  }
	  }
	  }
	  
	  l:if (bld2[target]<=0)
	  {if (target>1)
	  {target--;
	  }
	  else if (target<t2n)
	  {target++;
	  }
	  else 
	  {return 1;
	  }
	  }
	  if (att1[ytemp]/2>def2[target]/3)
	  {
	  	random2=sx(h+"round"+round+namet1[ytemp]+"Speed"+seed);
	  	if (spd[2][target]/4>=random2)
	  	{cout<<namet1[ytemp]<<"(Ѫ��Ϊ"<<bld1[ytemp]<<")"<<"��"<<namet2[target]<<"(Ѫ��Ϊ"<<bld2[target]<<")"<<"�������"<<att1[ytemp]/2-def2[target]/3+sx(h+"round"+round+namet1[ytemp]+"Fudong"+seed)/10<<"���˺�"<<"�����������˿�"<<endl; 
		  }
		  else
		  {
		  
	  
	 
	  if (mir[2][target]<=0)
	  {
	  
	  t2n=t2n-harm(2,target,att1[ytemp]/2-def2[target]/3+sx(h+"round"+round+namet1[ytemp]+"Fudong"+seed)/10,t1n,t2n,ytemp);
	  if (Gui_or_not==1)
  {writefile(t1n,t2n);
  }
	  if (t2n<=0)
	  {return 1;
	  }
}
else
{cout<<"����"<<namet2[target]<<"�����˻�ȥ"<<endl ;
t1n=t1n-harm(1,ytemp,att1[ytemp]/2-def2[target]/3+sx(h+"round"+round+namet1[ytemp]+"Fudong"+seed)/10,t1n,t2n,target);
mir[2][target]--;
if (t1n<=0)
{return 0;
}
}
}

    }
    else
    {cout<<namet1[ytemp]<<"(Ѫ��Ϊ"<<bld1[ytemp]<<")"<<"��"<<namet2[target]<<"(Ѫ��Ϊ"<<bld2[target]<<")"<<"�������"<<0<<"�˺�"<<"......."<<endl;
	}
}
else
{if (namet1[ytemp]=="�ұ�")
{cout<<"�ұƹ�����ȫ�����ȣ�������Ϊ���׵ĵ���ְ֡�"<<endl;
ltnh[1][ytemp]=0; 
goto guabi1;
}
cout<<namet1[ytemp]<<"(Ѫ��Ϊ"<<bld1[ytemp]<<")"<<"���׻��ˣ�һ�غϲ����ж�"<<endl;
ltnh[1][ytemp]=0;

 } 
      }
      Sleep(delay);
   }
 
    
   
   
      random1=sx(h+"round"+round+"2"+"Magic"+seed)%4+1;
   if (random1==1)
   {cout<<"�ڶ��Ӱڳ����ɷ���ȫ�ӹ�������25"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {att2[ntemp]=att2[ntemp]+25;
   }
   }
   else if (random1==2)
   {cout<<"�ڶ��Ӱڳ���ʯ����ȫ�ӷ�������25"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {def2[ntemp]=def2[ntemp]+25;
   }
   }
    else if (random1==3)
   {cout<<"�ڶ��Ӱڳ�Ӱ�編��ȫ���ٶȼ�40"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {spd[2][ntemp]=spd[2][ntemp]+40;
   }
   }
      else if (random1==4)
   {cout<<"�ڶ��Ӱڳ���������ȫ��ȫ���Լ�10"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {def2[ntemp]=def2[ntemp]+10;
   att2[ntemp]=att2[ntemp]+10;
   spd[2][ntemp]=spd[2][ntemp]+10;
   }
   }
   
   
   for (ytemp=1;ytemp<=t2n;ytemp++)
   {att2[ytemp]=sx(namet2[ytemp]+"Attack");
   def2[ytemp]=sx(namet2[ytemp]+"Defend");
   spd[2][ytemp]=sx(namet2[ytemp]+"Speed");
   }
  
   for (ytemp=1;ytemp<=t2n;ytemp++)
   {
  
   bjCD2[ytemp]--;
   tbCD2[ytemp]--;
   cureCD[2][ytemp]--;
   ltnCD[2][ytemp]--; 
   refCD[2][ytemp]--;
   sldCD[2][ytemp]--;
     grhCD[2][ytemp]--;
   if (bld2[ytemp]>0)
      {if (ltnh[2][ytemp]==0)
      {
	  guabi2:if (namet2[ytemp]=="�ұ�")
      {random3=sx(h+"round"+round+"KaiGua"+"2"+seed)%4+1;
      if (random3==1)
      {cout<<"�ұƴ�����Ѫ��"<<endl;
      Suoxue=1;
	  }
	  else if (random3==2)
	  {cout<<"�ұƴ��˱�ͷ��" <<endl;
	  Baotou=1;
	  }
	  else
	  {cout<<"�ұ���غ�û�п���"<<endl;
	  }
}
	  round=round+"1";
	  random=sx(h+"round"+round+namet2[ytemp]+"Choice"+seed)*7;
      target=sx(h+"round"+round+namet2[ytemp]+"Target"+seed)%t1n+1;
     c:if (random<=bj2[ytemp]&&bjCD2[ytemp]<=0)
      {
	  if (namet2[ytemp]=="Rinick")
      {cout<<"Rinickʹ������������ɱ֮��,"<<namet1[target]<<"��ǿ�л�ɱ"<<endl;
      if (bld2[ytemp]>=bld1[target]*2/3)
      {cout<<"Rinick������ʧ��"<<bld1[target]*2/3<<"��Ѫ "<<endl;
      bld2[ytemp]=bld2[ytemp]-bld1[target]*2/3;
	  }
	  else
	  {cout<<"Rinick��������ֻʣ��һ��Ѫ"<<endl;
	  bld2[ytemp]=1;
	  }
	t1n=t1n-harm(1,target,inf*100,t1n,t2n,ytemp);
	goto l1;
	  }
	  
	  Superattack(2,ytemp,t2n);
      if (namet2[ytemp]=="��������")
      {t2n++;
	  }
	  }
	  else if (random>100 && random<=tb2[ytemp]+100 && tbCD2[ytemp]<=0)
	  {if (namet2[ytemp]=="Rinick")
	  {cout<<"Rinick������NULLֵ����"<<endl;
	  cout<<"�Է����з����ܣ���Ѫ��ȫ���ԶԷ��Լ���ɵ����˺���Ϊ�Լ���Ѫ"<<endl;
	  for (int ftemp=1;ftemp<=t1n;ftemp++)
	  {t1n=t1n-harm(1,ftemp,mir[1][ftemp]*50,t1n,t2n,ytemp);
	  t1n=t1n-harm(1,ftemp,sldn[1][ftemp]*2,t1n,t2n,ytemp);
	  bld2[ytemp]=bld2[ytemp]+mir[1][ftemp]*50;
	  bld2[ytemp]=bld2[ytemp]+sldn[1][ftemp]*2;
	   }
	   goto l1; 
	  }
	  Superdefend(2,ytemp,t2n);
	  }
	  else if (random>200 && random<=cure[2][ytemp]+200 && cureCD[2][ytemp]<=0)
	  {Cure(2,ytemp,t2n);
	  }
	   else if (random>300 && random<=ltn[2][ytemp]+300 && ltnCD[2][ytemp]<=0)
	  {if (namet2[ytemp]=="Rinick")
      {cout<<"Rinick���õk������ʹ�������,";
      cout<<"���ֵĹ�����Ѫ��ϴ��"<<endl;
      for (int itemp=1;itemp<=t1n;itemp++)
      {att1[itemp]=sx(h+"round"+round+"Rinick"+"2"+"Attack"+seed);
      if (sx(h+"round"+round+"Rinick"+"2"+"Blood"+seed)*3>=bld1[itemp])
      {
	  }
	  else
	  {
      bld1[itemp]=sx(h+"round"+round+"Rinick"+"2"+"Blood"+seed)*3;
	  }
	  def1[itemp]=sx(h+"round"+round+"Rinick"+"2"+"Defend"+seed);
      spd[1][itemp]=sx(h+"round"+round+"Rinick"+"2"+"Speed"+seed);
	  }
	  goto l1;
	  }
	  
	  lightning(2,ytemp,target);
	  }
	   else if (random>400 && random<=rif[2][ytemp]+400 && refCD[2][ytemp]<=0)
	  {reflect(2,ytemp,t2n,t1n);
	  }
	   else if (random>500 && random<=sld[2][ytemp]+500 && sldCD[2][ytemp]<=0)
	  {if (namet2[ytemp]=="Rinick")
	  {if (bld2[ytemp]<=900)
	  {
	  
	  cout<<"Rinick��ʱ���м�ȡ������������ʧѪ��һ���ֻ�Ϊ��Ѫ��"<<endl;
	  cout<<"Rinick�����"<<(1536-bld2[ytemp])/6<<"����Ѫ��" <<endl;
	  sldn[2][ytemp]=sldn[2][ytemp]+(1536-bld2[ytemp])/6;
}
else
{cout<<"Rinick�ӿռ��м�ȡ������������Ѫ��һ���ֻ�Ϊ��Ѫ��"<<endl;
cout<<"Rinick�����"<<bld2[ytemp]/6<<"����Ѫ��"<<endl;
sldn[2][ytemp]=sldn[2][ytemp]+bld2[ytemp]/6;
}
	  goto l1;
	  }
	  Shield(2,ytemp);
	  }
	  	  else if (random>600 && random<=grh[2][ytemp]+600 && grhCD[2][ytemp]<=0)
	  {grhCD[2][ytemp]=4;
	  cout<<namet2[ytemp]<<"������ɨ֮��,�ԶԷ�ȫ�����"<<att2[ytemp]/2<<"���˺�"<<endl;
	  for (int atemp=1;atemp<=t1n;atemp++)
	  {t1n=t1n-harm(1,atemp,att2[ytemp]/2,t1n,t2n,ytemp);
	  if (t1n==0)
	  {return 0;
	  }
	  }
	  }
	  l1: if (bld1[target]<=0)
	  {if (target>1)
	  {target--;
	  }
	  else if (target<t1n)
	  {target++;
	  }
	  else 
	  {return 0;
	  }
	  }
	  if (att2[ytemp]/2>def1[target]/3)
	  {  random2=sx(h+"round"+round+namet2[ytemp]+"Speed"+seed);
	  	if (spd[1][target]/4>=random2)
	  	{cout<<namet2[ytemp]<<"(Ѫ��Ϊ"<<bld2[ytemp]<<")"<<"��"<<namet1[target]<<"(Ѫ��Ϊ"<<bld1[target]<<")"<<"�������"<<att2[ytemp]/2-def1[target]/3+sx(h+"round"+round+namet2[ytemp]+"Fudong"+seed)/10<<"���˺�"<<"�����������˿�"<<endl ;
		  }
		  else
		  {
		  
	  
	  	  
	  if (mir[1][target]<=0)
	  {
	  t1n=t1n-harm(1,target,att2[ytemp]/2-def1[target]/3+sx(h+"round"+round+namet2[ytemp]+"Fudong"+seed)/10,t1n,t2n,ytemp);
	  if (Gui_or_not==1)
  {writefile(t1n,t2n);
  }
          if (t1n<=0)
          {return 0;
		  }
	
	}
	else
	{cout<<"����"<<namet1[target]<<"�����˻�ȥ"<<endl ;
t2n=t2n-harm(2,ytemp,att2[ytemp]/2-def1[target]/3+sx(h+"round"+round+namet2[ytemp]+"Fudong"+seed)/10,t1n,t2n,target);
mir[1][target]--;
if (t2n<=0)
{return 1;
}
}
}
	}

else
{cout<<namet2[ytemp]<<"(Ѫ��Ϊ"<<bld2[ytemp]<<")"<<"��"<<namet1[target]<<"(Ѫ��Ϊ"<<bld1[target]<<")"<<"�������"<<0<<"�˺�"<<"......."<<endl;
}
      }
      else
      {if (namet2[ytemp]=="�ұ�")
{cout<<"�ұƹ�����ȫ�����ȣ�������Ϊ���׵ĵ���ְ֡�"<<endl;
ltnh[2][ytemp]=0; 
goto guabi2;
}
	  cout<<namet2[ytemp]<<"(Ѫ��Ϊ"<<bld2[ytemp]<<")"<<"���׻��ˣ�һ�غϲ����ж�"<<endl;
      ltnh[2][ytemp]=0;
	  }
  }
  Sleep(delay);
}
 
    
      
   
      for (ytemp=1;ytemp<=t1n;ytemp++)
   {att1[ytemp]=sx(namet1[ytemp]+"Attack");
   def1[ytemp]=sx(namet1[ytemp]+"Defend");
   spd[1][ytemp]=sx(namet1[ytemp]+"Speed");
   }
   
if (t1n<=0)
{return 0;
}
if (t2n<=0)
{return 1;
}
   
   //cout<<t1n<<" "<<t2n;
   
   

}
}



void SXCK()
{   cout<<"Input your name";
    cin>>name;
     
    //cout<<attack<<endl<<defend<<endl; 
    
    cout<<"������Ϊ"<<sx(name+"Attack")<<endl;
	 cout<<"������Ϊ"<<sx(name+"Defend")<<endl;
	 cout<<"�ٶ�Ϊ"<<sx(name+"Speed")<<endl;
	 cout<<"Ѫ��Ϊ"<<sx(name+"Blood")*3<<endl;
	 cout<<"��������"<<sx(name+"Superattack")<<"%"<<endl;
	 cout<<"���ڸ���"<<sx(name+"Superdefend")<<"%"<<endl;
	 cout<<"����������"<<sx(name+"Cure")<<"%"<<endl;
	 cout<<"�׻�������"<<sx(name+"Lightning")<<"%"<<endl;
	 cout<<"���˸���"<<sx(name+"Reflect")<<"%"<<endl;
	 cout<<"��Ѫħ��������"<<sx(name+"Shield")<<"%"<<endl;
	 cout<<"��ɨ֮�и���"<<sx(name+"Groupharm")<<"%"<<endl;
	 system("pause");
 } 
 
void cehao(int threadnum,string qz,int ytemp)
{cr[threadnum]=sx(qz+ytemp+"Attack")+sx(qz+ytemp+"Defend")+sx(qz+ytemp+"Blood")+sx(qz+ytemp+"Superattack")+sx(qz+ytemp+"Superdefend")+sx(qz+ytemp+"Cure")+sx(qz+ytemp+"Lightning")+sx(qz+ytemp+"Reflect")+sx(qz+ytemp+"Shield")+sx(qz+ytemp+"Groupharm")+sx(qz+ytemp+"Speed");
}

//Test
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{int method,team1num,team2num,utemp,bossnum,delaym,winnum=0,mtemp,tt1n,tt2n,ctemp,ltemp;
string qzm,h,testtest="test";
string op[256],op1[256];
string hp;
clock_t   start,   finish; 
system("del input.txt"); 
freopen("input.txt","w",stdout);

cout<<1<<endl;
cout<<"a 1 1 1 1 1" <<endl;
cout<<"temp"<<endl;
freopen("CON","w",stdout);
 
cout<<"1.�鿴����"<<endl<<"2.��ս"<<endl<<"3.��սboss"<<endl<<"4.��������"<<endl<<"5.ʤ�ʲ���"<<endl<<"6.���ò����"<<endl;
cin>>method;
if (method==1)
{SXCK();
}
else if (method==2)
{Gui_or_not=1;
cout<<"�����һ������"<<endl;
cin>>team1num;
cout<<"����ڶ�������"<<endl;
cin>>team2num; 
cout<<"�����һ���Ա�����б�ʾһ������"<<endl;
for (utemp=1;utemp<=team1num;utemp++)
{cin>>namet1[utemp];
}
cout<<"����ڶ����Ա�����б�ʾһ������"<<endl;
for (utemp=1;utemp<=team2num;utemp++)
{cin>>namet2[utemp];
}
cout<<"����seed"<<endl;
cin>>fseed;
cout<<"�����ӳ�"<<endl;
cin>>delaym;
if (fight(team1num,team2num,fseed,delaym)==1)
{cout<<"һ��Ӯ�ˣ�";

}
else
{cout<<"����Ӯ�ˣ�";
}
Gui_or_not=0;
}
else if (method==6)
{cout<<"������ǰ׺"<<endl;
cin>>qzm;
int request;
cout<<"������������Ҫ��(1100���ֽ���960)" ; 
cin>>request;
int jnum;
cout<<"������������";
cin>>jnum;
start=clock();
for (ltemp=0;ltemp<=jnum/12-1;ltemp++)
{thread t1(cehao,1,qzm,ltemp*12);t1.detach();
thread t2(cehao,2,qzm,ltemp*12+1);t2.detach();
thread t3(cehao,3,qzm,ltemp*12+2);t3.detach();
thread t4(cehao,4,qzm,ltemp*12+3);t4.detach();
thread t5(cehao,5,qzm,ltemp*12+4);t5.detach();
thread t6(cehao,6,qzm,ltemp*12+5);t6.detach();
thread t7(cehao,7,qzm,ltemp*12+6);t7.detach();
thread t8(cehao,8,qzm,ltemp*12+7);t8.detach();
thread t9(cehao,9,qzm,ltemp*12+8);t9.detach();
thread t10(cehao,10,qzm,ltemp*12+9);t10.detach();
thread t11(cehao,11,qzm,ltemp*12+10);t11.detach();
thread t12(cehao,12,qzm,ltemp*12+11);t12.detach();
for (int xtemp=1;xtemp<=12;xtemp++)
{if (cr[xtemp]>=request)
{cout<<qzm<<ltemp*12+xtemp-1<<endl;
}
}
 } 
  finish   =   clock();  
  cout<<finish-start<<endl;
}
else if (method==3)
{cout<<"��ѡ��boss"<<endl<<"1.RailGun"<<endl<<"2.��������"<<endl<<"3.�ұ�"<<endl<<"4.����֮��---Rinick"<<endl;
int htemp;
cin>>htemp;
if (htemp==1)
{cout<<"������ս����"<<endl;
cin>>bossnum;
cout<<"������������ս����"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="RailGun";
if (fight(bossnum,1,"",300)==1)
{cout<<"��Ӯ�ˣ�";

}
else
{cout<<"�����ˣ�";
}
  
}

else if (htemp==2)
{cout<<"������ս����"<<endl;
cin>>bossnum;
cout<<"������������ս����"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="��������";
if (fight(bossnum,1,"",300)==1)
{cout<<"��Ӯ�ˣ�";

}
else
{cout<<"�����ˣ�";
}
  
}
else if (htemp==3)
{cout<<"������ս����"<<endl;
cin>>bossnum;
cout<<"������������ս����"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="�ұ�";
if (fight(bossnum,1,"",300)==1)
{cout<<"��Ӯ�ˣ�";

}
else
{cout<<"�����ˣ�";
}
  
}
else if (htemp==4)
{cout<<"������ս����"<<endl;
cin>>bossnum;
cout<<"������������ս����"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="Rinick";
if (fight(bossnum,1,"",300)==1)
{cout<<"��Ӯ�ˣ�";

}
else
{cout<<"�����ˣ�";
}
  
}
}


else if (method==4)
{cout<<"������Ҫ���Եĺ�";
cin>>hp;
namet1[1]=hp;
freopen("temp.out","w",stdout);

for (mtemp=1;mtemp<=10000;mtemp++)
{h=testtest+mtemp;
if (mtemp%2==0)
{

namet1[1]=hp;namet2[1]=h;
if (fight(1,1,"",0)==1)
{winnum++;
}
}
else
{namet1[1]=h;namet2[1]=hp;
if (fight(1,1,"",0)==0)
{winnum++;
}
}
}
freopen("CON", "w", stdout);
cout<<winnum<<"/10000";
}

else if (method==5)
{cout<<"�����һ�Ӳ�������"<<endl;cin>>tt1n;
cout<<"����ڶ��Ӳ�������"<<endl;cin>>tt2n;
cout<<"�����һ�ӳ�Ա"<<endl;
for (ctemp=1;ctemp<=tt1n;ctemp++)
{cin>>op[ctemp];
}
cout<<"����ڶ��ӳ�Ա"<<endl;
for (ctemp=1;ctemp<=tt2n;ctemp++)
{cin>>op1[ctemp];
}
freopen("temp.txt","w",stdout);
for (mtemp=1;mtemp<=10000;mtemp++)
{
	freopen("temp.txt","a",stdout);
	h=testtest+mtemp;
	if (mtemp%2==0)
	{for (ctemp=1;ctemp<=tt1n;ctemp++)
{
namet1[ctemp]=op[ctemp];
}
for (ctemp=1;ctemp<=tt2n;ctemp++)
{
namet2[ctemp]=op1[ctemp];
}

	
	if (fight(tt1n,tt2n,h,0)==1)
	{winnum++;
	}
	
}

else
{for (ctemp=1;ctemp<=tt1n;ctemp++)
{
namet2[ctemp]=op[ctemp];
}
for (ctemp=1;ctemp<=tt2n;ctemp++)
{
namet1[ctemp]=op1[ctemp];
}
if (fight(tt2n,tt1n,h,0)==0)
	{
	winnum++;
	}
	
 } 
 
}
freopen("con", "w", stdout);
cout<<"��һ��Ӯ��"<<winnum<<"/10000"; 
 } 


system("pause");
 
    return 0;
}
