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
    //扩展成K*512位
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
    //开始计算
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
	
	    if (s=="喷气翼龙Attack")
    {return 66;
	}
	else if (s=="喷气翼龙Defend")
	{return 66;
	}
		else if (s=="喷气翼龙Superattack")
	{return 80;
	}
		else if (s=="喷气翼龙Superdefend")
	{return 80;
	}
		else if (s=="喷气翼龙Blood")
	{return 66;
	}
	else if (s=="喷气翼龙Cure")
	{return 80;
	}
		else if (s=="喷气翼龙Lightning")
	{return 80;
	}
	else if (s=="喷气翼龙Reflect")
	{return 80;
	}
		else if (s=="喷气翼龙Shield")
	{return 80;
	}
		else if (s=="喷气翼龙Groupharm")
	{return 80;
	}
		else if (s=="喷气翼龙Speed")
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
	
	
			    if (s=="挂逼Attack")
    {return 120;
	}
	else if (s=="挂逼Defend")
	{return 120;
	}
		else if (s=="挂逼Superattack")
	{return 100;
	}
		else if (s=="挂逼Superdefend")
	{return 100;
	}
		else if (s=="挂逼Blood")
	{return 100; 
	}
	else if (s=="挂逼Cure")
	{return 100;
	}
	else if (s=="挂逼Lightning")
	{return 100;
	}
		else if (s=="挂逼Reflect")
	{return 100;
	}
     	else if (s=="挂逼Speed")
	{return 100;
	}
		else if (s=="挂逼Shield")
	{return 100;
	}
		else if (s=="挂逼Groupharm")
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

//由于+=会调用+号，所以 += 必须写在 + 号重载后面

string&  operator+=(string &content, int number) {

	return content = content + number;

}

int Superattack(int team,int player,int tpl)
{

if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld1[player]<<")"<<"修改了游戏代码，自身攻击力变为无限"<<endl; 
att1[player]=inf;
return 0;
 
}
else if (namet1[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player]<<")"<<"召唤了一匹小马驹"<<endl;
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
cout<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"暴击！攻击力翻倍"<<endl;
bjCD1[player]=1;
}
else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld2[player]<<")"<<"修改了游戏代码，自身攻击力变为无限"<<endl;
att2[player]=inf;
return 0;
 
}
else if (namet2[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld2[player]<<")"<<"召唤了一匹小马驹"<<endl;
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
cout<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"暴击！攻击力翻倍"<<endl; 
bjCD2[player]=1;
}
}
int Superdefend(int team1,int player1,int tpl)
{if (team1==1)
{if (namet1[player1]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld1[player1]<<")"<<"修改了游戏代码，自身防御力变为无限"<<endl;
def1[player1]=inf;
return 0;
}
else if (namet1[player1]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player1]<<")"<<"使用小马匹的力量加强了自身,攻击防御各加50，生命恢复70"<<endl;
def1[player1]= def1[player1]+50;
att1[player1]= att1[player1]+50;
bld1[player1]= bld1[player1]+70;
return 0; 
}
def1[player1]=def1[player1]*2;
cout<<namet1[player1]<<"(血量为"<<bld1[player1]<<")"<<"发动铁壁防御力翻倍"<<endl;
tbCD1[player1]=1;
}
else
{if (namet2[player1]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld2[player1]<<")"<<"修改了游戏代码，自身防御力变为无限"<<endl;
def2[player1]=inf;
return 0;
}
else if (namet2[player1]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld2[player1]<<")"<<"使用小马匹的力量加强了自身,攻击防御各加50，生命恢复70"<<endl;
def2[player1]= def2[player1]+50;
att2[player1]= att2[player1]+50;
bld2[player1]= bld2[player1]+70;
return 0; 
}
def2[player1]=def2[player1]*2;
cout<<namet2[player1]<<"(血量为"<<bld2[player1]<<")"<<"发动铁壁防御力翻倍"<<endl;
bjCD2[player1]=1;
}
}

int Cure(int team,int player,int tpl)
{int btemp;
cureCD[team][player]=2;
if (team==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld1[player]<<")"<<"修改了游戏代码，自身回血100点"<<endl;
bld1[player]=bld1[player]+100;
return 0;
}
else if (namet1[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player]<<")"<<"给他的小马驹们回血20点"<<endl; 
 for (btemp=1;btemp<=tpl;btemp++)
{if (namet1[btemp]=="littlepony")
{

bld1[btemp]=bld1[btemp]+20;
}
}
return 0; 
}
cout<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"为全队回血"<<att1[player]/tpl<<"点"<<endl;
for (btemp=1;btemp<=tpl;btemp++)
{if (bld1[btemp]>0 && bld1[btemp]<=500)
{ 
bld1[btemp]=bld1[btemp]+att1[player]/tpl;
} 
}

}
else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld2[player]<<")"<<"修改了游戏代码，自身回血100点"<<endl;
bld2[player]=bld2[player]+100;
return 0;
}
else if (namet2[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player]<<")"<<"给他的小马驹们回血20点"<<endl;
 for (btemp=1;btemp<=tpl;btemp++)
{if (namet2[btemp]=="littlepony")
{

bld2[btemp]=bld2[btemp]+20;
}
}
return 0; 
}
cout<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"为全队回血"<<att2[player]/tpl<<"点"<<endl;
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
{cout<<"RailGun"<<"(血量为"<<bld1[player]<<")"<<"使用万雷霹雳，连续三个对手遭受雷电惩戒"<<endl;
ltnh[2][kill]=1;
ltnh[2][kill+1]=1;
if (kill>1)
{ltnh[2][kill-1]=1;
}
att1[player]=att1[player]*3;
return 0;
}
else if (namet1[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player]<<")"<<"召唤雷电小马，对对手进行两倍伤害破甲攻击"<<endl;
att1[player]=(att1[player]+2*def2[kill]/3)*2;
ltnh[2][kill]=1;
return 0;
}
cout<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"召唤天雷对对手进行破甲攻击"<<endl;
att1[player]=att1[player]+2*def2[kill]/3;
ltnh[2][kill]=1;
}



else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld2[player]<<")"<<"使用万雷霹雳，连续三个对手遭受雷电惩戒"<<endl;
ltnh[1][kill]=1;
ltnh[1][kill+1]=1;
if (kill>1)
{ltnh[1][kill-1]=1;
}
att2[player]=att2[player]*3;
return 0;
}
else if (namet2[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld2[player]<<")"<<"召唤雷电小马，对对手进行两倍伤害破甲攻击"<<endl;
att2[player]=(att2[player]+2*def1[kill]/3)*2;
ltnh[1][kill]=1;
return 0;
}
cout<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"召唤天雷对对手进行破甲攻击"<<endl;
att2[player]=att2[player]+2*def1[kill]/3;
ltnh[1][kill]=1;
}
}


int harm(int team,int player,int destroy,int team1p,int team2p,int harmer)
{int gtemp,l;
if (team==1)
{if (namet1[player]=="挂逼" && Suoxue==1 )
if (namet2[harmer]=="RailGun")
{cout<<"RailGun发现了挂逼"<<"("<<"血量为"<<bld1[player]<<")"<<"试图锁血并制裁了他"<<endl;
Suoxue=0;
if (bld1[player]>destroy)
{cout<<"他的血量变为1"<<endl;
bld1[player]=1;
return 0;
}
else
{Suoxue=0;
return harm(1,player,destroy,team1p,team2p,harmer);
}
}
else
{cout<<namet2[harmer]<<"(血量为"<<bld2[harmer]<<")"<<"对"<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"造成"<<destroy<<"点伤害"<<endl;
Suoxue=0;
cout<<"挂逼发动锁血挂，他仅仅只被扣除一滴血"<<endl;
return harm(1,player,1,team1p,team2p,harmer);
}


if (namet2[harmer]=="挂逼" && Baotou==1)
{if (namet1[player]=="RailGun")
{cout<<"RailGun发现挂逼"<<"("<<"血量为"<<bld2[harmer]<<")"<<"试图使用爆头挂并制裁了他，他的血量变为1"<<endl ;
bld2[harmer]=1;
Baotou=0;
return 0;
 }
 else
 {cout<<"挂逼使用爆头挂，对对方造成了10倍伤害"<<endl;
 Baotou=0;
 return harm(1,player,destroy*10,team1p,team2p,harmer);
  } 
}
}

if (team==2)
{if (namet2[player]=="挂逼" && Suoxue==1 )
if (namet1[harmer]=="RailGun")
{cout<<"RailGun发现了挂逼"<<"("<<"血量为"<<bld2[player]<<")"<<"试图锁血并制裁了他"<<endl;
Suoxue=0;
if (bld2[player]>destroy)
{cout<<"他的血量变为1"<<endl;
bld2[player]=1;
return 0;
}
else
{Suoxue=0;
return harm(2,player,destroy,team1p,team2p,harmer);
}
}
else
{cout<<namet1[harmer]<<"(血量为"<<bld1[harmer]<<")"<<"对"<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"造成"<<destroy<<"点伤害"<<endl;
Suoxue=0;
cout<<"挂逼发动锁血挂，他仅仅只被扣除一滴血"<<endl;
return harm(2,player,1,team1p,team2p,harmer);
}


if (namet1[harmer]=="挂逼" && Baotou==1)
{if (namet2[player]=="RailGun")
{cout<<"RailGun发现挂逼"<<"("<<"血量为"<<bld1[harmer]<<")"<<"试图使用爆头挂并制裁了他，他的血量变为1"<<endl ;
bld1[harmer]=1;
Baotou=0;
return 0;
 }
 else
 {cout<<"挂逼使用爆头挂，对对方造成了10倍伤害"<<endl;
 Baotou=0;
 return harm(2,player,destroy*10,team1p,team2p,harmer);
  } 
}
}

if (team==1)
{cout<<namet2[harmer]<<"(血量为"<<bld2[harmer]<<")"<<"对"<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"造成"<<destroy<<"点伤害"<<endl;
 
if (sldn[1][player]!=0)
{
if (sldn[1][player]>=destroy)
{cout<<namet1[player]<<"使用吸血魔盾吸收了"<<destroy<<"点伤害"<<endl;
bld1[player]=bld1[player]+destroy; 
sldn[1][player]=sldn[1][player]-destroy;
if (sldn[1][player]<=0)
{cout<<"他的吸血盾破碎了";
}
return 0;
}
else 
{l=sldn[1][player];
cout<<namet1[player]<<"使用吸血魔盾吸收了"<<sldn[1][player]<<"点伤害"<<endl;
cout<<"他的吸血盾破碎了"<<endl;
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
  {cout<<"Rinick被击杀了，祂还剩"<<Rinicklife[1][player]-1<<"条命"<<endl;
  cout<<"祂这条命的初始生命为"<<1536-(4-Rinicklife[1][player])*500<<endl;
  Rinicklife[1][player]--;
  bld1[player]=1536-(3-Rinicklife[1][player])*500;
  return 0;
  }
  cout<<namet1[player]<<"被击杀了"<<endl ;
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
{cout<<namet1[harmer]<<"(血量为"<<bld1[harmer]<<")"<<"对"<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"造成"<<destroy<<"点伤害"<<endl;
if (sldn[2][player]!=0)
{
if (sldn[2][player]>=destroy)
{cout<<namet2[player]<<"使用吸血魔盾吸收了"<<destroy<<"点伤害"<<endl;
bld2[player]=bld2[player]+destroy; 
sldn[2][player]=sldn[2][player]-destroy;
if (sldn[2][player]<=0)
{cout<<"他的吸血盾破碎了";
}
return 0;
}
else 
{l=sldn[2][player];
cout<<namet2[player]<<"使用吸血魔盾吸收了"<<sldn[2][player]<<"点伤害"<<endl;
cout<<"他的吸血盾破碎了"<<endl;
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
  {cout<<"Rinick被击杀了，祂还剩"<<Rinicklife[2][player]-1<<"条命"<<endl;
  cout<<"祂这条命的初始生命为"<<1536-(4-Rinicklife[2][player])*500<<endl;
  Rinicklife[2][player]--;
  bld2[player]=1536-(3-Rinicklife[2][player])*500;
  return 0;
  }
  cout<<namet2[player]<<"被击杀了"<<endl ;
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
  cout<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"为自己添加了"<<att1[player]/2<<"点吸血盾"<<endl;
  }
   if (team==2)
  {sldn[2][player]=att2[player]/2;
  cout<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"为自己添加了"<<att2[player]/2<<"点吸血盾"<<endl;
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
{cout<<"RailGun"<<"(血量为"<<bld1[player]<<")"<<"修改了代码，反弹下一回合所有伤害"<<endl;
mir[1][player]=mir[1][player]+opponum;
return 0;
}
else if (namet1[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld1[player]<<")"<<"祭献他的小马";
for (int btemp=1;btemp<=ournum;btemp++)
{

if (namet1[btemp]=="littlepony" && bld1[btemp]>=60)
{bld1[btemp]=bld1[btemp]-60;
horsenum++;
 }
}
cout<<horsenum<<"匹，每马减少60生命，为自己叠上"<<horsenum<<"个护盾"<<endl;
mir[1][player]=mir[1][player]+horsenum; 
return 0;
}
cout<<namet1[player]<<"(血量为"<<bld1[player]<<")"<<"为自己增加了一重反弹盾"<<endl;
}

else
{if (namet2[player]=="RailGun")
{cout<<"RailGun"<<"(血量为"<<bld2[player]<<")"<<"修改了代码，反弹下一回合所有伤害"<<endl;
mir[2][player]=mir[2][player]+opponum;
return 0;
}
else if (namet2[player]=="喷气翼龙")
{cout<<"喷气翼龙"<<"(血量为"<<bld2[player]<<")"<<"祭献他的小马";
for (int btemp=1;btemp<=ournum;btemp++)
{

if (namet2[btemp]=="littlepony" && bld2[btemp]>=60)
{bld2[btemp]=bld2[btemp]-60;
horsenum++;
 }
}
cout<<horsenum<<"匹，每马减少60生命，为自己叠上"<<horsenum<<"个护盾"<<endl;
mir[2][player]=mir[2][player]+horsenum; 
return 0;
}
cout<<namet2[player]<<"(血量为"<<bld2[player]<<")"<<"为自己增加了一重反弹盾"<<endl;
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
   {cout<<"回合过多自动退出"<<endl;
   return 3;
   }
   
   //cout<<t1n<<" "<<t2n;
   random1=sx(h+"round"+round+"1"+"Magic"+seed)%4+1;
   if (random1==1)
   {cout<<"第一队摆出诛仙法阵，全队攻击力加25"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {att1[ntemp]=att1[ntemp]+25;
   }
   }
   else if (random1==2)
   {cout<<"第一队摆出磐石法阵，全队防御力加25"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {def1[ntemp]=def1[ntemp]+25;
   }
   }
    else if (random1==3)
   {cout<<"第一队摆出影风法阵，全队速度加40"<<endl;
   for (ntemp=1;ntemp<=t1n;ntemp++)
   {spd[1][ntemp]=spd[1][ntemp]+40;
   }
   }
      else if (random1==4)
   {cout<<"第一队摆出遁气法阵，全队全属性加10"<<endl;
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
	  guabi1:if (namet1[ytemp]=="挂逼")
      {random3=sx(h+"round"+round+"KaiGua"+seed)%4+1;
      if (random3==1)
      {cout<<"挂逼打开了锁血挂"<<endl;
      Suoxue=1;
	  }
	  else if (random3==2)
	  {cout<<"挂逼打开了爆头挂" <<endl;
	  Baotou=1;
	  }
	  else
	  {cout<<"挂逼这回合没有开挂"<<endl;
	  }
}
	   
	  round=round+"1";
	  random=sx(h+"round"+round+namet1[ytemp]+"Choice"+seed)*7;
      target=sx(h+"round"+round+namet1[ytemp]+"Target"+seed)%t2n+1;
	  b:if (random<=bj1[ytemp]&&bjCD1[ytemp]<=0)
      {if (namet1[ytemp]=="Rinick")
      {cout<<"Rinick使用了神力·必杀之诀,"<<namet2[target]<<"被强行击杀"<<endl;
      if (bld1[ytemp]>=bld2[target]*2/3)
      {cout<<"Rinick自身损失了"<<bld2[target]*2/3<<"点血 "<<endl;
      bld1[ytemp]=bld1[ytemp]-bld2[target]*2/3;
	  }
	  else
	  {cout<<"Rinick神力大损，只剩下一滴血"<<endl;
	  bld1[ytemp]=1;
	  }
	t2n=t2n-harm(2,target,inf*100,t1n,t2n,ytemp);
	goto l;
	  }
	  
	  
	  Superattack(1,ytemp,t1n);
      if (namet1[ytemp]=="喷气翼龙")
      {t1n++;
	  }
	  }
	  else if (random>100 && random<=tb1[ytemp]+100 && tbCD1[ytemp]<=0)
	  {if (namet1[ytemp]=="Rinick")
	  {cout<<"Rinick发动了NULL值净化"<<endl;
	  cout<<"对方所有反弹盾，吸血盾全部对对方自己造成等量伤害并为自己回血"<<endl;
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
      {cout<<"Rinick运用祂的神力使世界崩坏,";
      cout<<"对手的攻防速血被洗牌"<<endl;
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
	  
	  cout<<"Rinick从时空中汲取神力，将已损失血量一部分化为吸血盾"<<endl;
	  cout<<"Rinick获得了"<<(1536-bld1[ytemp])/6<<"点吸血盾" <<endl;
	  sldn[1][ytemp]=sldn[1][ytemp]+(1536-bld1[ytemp])/6;
}
else
{cout<<"Rinick从空间中汲取神力，将现有血量一部分化为吸血盾"<<endl;
cout<<"Rinick获得了"<<bld1[ytemp]/6<<"点吸血盾"<<endl;
sldn[1][ytemp]=sldn[1][ytemp]+bld1[ytemp]/6;
}
	  goto l;
	  }
	  Shield(1,ytemp);
	  }
	  else if (random>600 && random<=grh[1][ytemp]+600 && grhCD[1][ytemp]<=0)
	  {grhCD[1][ytemp]=4;
	  cout<<namet1[ytemp]<<"发动横扫之刃,对对方全体造成"<<att1[ytemp]/2<<"点伤害"<<endl;
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
	  	{cout<<namet1[ytemp]<<"(血量为"<<bld1[ytemp]<<")"<<"对"<<namet2[target]<<"(血量为"<<bld2[target]<<")"<<"攻击造成"<<att1[ytemp]/2-def2[target]/3+sx(h+"round"+round+namet1[ytemp]+"Fudong"+seed)/10<<"点伤害"<<"，但被闪避了开"<<endl; 
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
{cout<<"但被"<<namet2[target]<<"反弹了回去"<<endl ;
t1n=t1n-harm(1,ytemp,att1[ytemp]/2-def2[target]/3+sx(h+"round"+round+namet1[ytemp]+"Fudong"+seed)/10,t1n,t2n,target);
mir[2][target]--;
if (t1n<=0)
{return 0;
}
}
}

    }
    else
    {cout<<namet1[ytemp]<<"(血量为"<<bld1[ytemp]<<")"<<"对"<<namet2[target]<<"(血量为"<<bld2[target]<<")"<<"攻击造成"<<0<<"伤害"<<"......."<<endl;
	}
}
else
{if (namet1[ytemp]=="挂逼")
{cout<<"挂逼购买了全服喇叭：“你以为你雷的到你爸爸”"<<endl;
ltnh[1][ytemp]=0; 
goto guabi1;
}
cout<<namet1[ytemp]<<"(血量为"<<bld1[ytemp]<<")"<<"被雷击了，一回合不能行动"<<endl;
ltnh[1][ytemp]=0;

 } 
      }
      Sleep(delay);
   }
 
    
   
   
      random1=sx(h+"round"+round+"2"+"Magic"+seed)%4+1;
   if (random1==1)
   {cout<<"第二队摆出诛仙法阵，全队攻击力加25"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {att2[ntemp]=att2[ntemp]+25;
   }
   }
   else if (random1==2)
   {cout<<"第二队摆出磐石法阵，全队防御力加25"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {def2[ntemp]=def2[ntemp]+25;
   }
   }
    else if (random1==3)
   {cout<<"第二队摆出影风法阵，全队速度加40"<<endl;
   for (ntemp=1;ntemp<=t2n;ntemp++)
   {spd[2][ntemp]=spd[2][ntemp]+40;
   }
   }
      else if (random1==4)
   {cout<<"第二队摆出遁气法阵，全队全属性加10"<<endl;
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
	  guabi2:if (namet2[ytemp]=="挂逼")
      {random3=sx(h+"round"+round+"KaiGua"+"2"+seed)%4+1;
      if (random3==1)
      {cout<<"挂逼打开了锁血挂"<<endl;
      Suoxue=1;
	  }
	  else if (random3==2)
	  {cout<<"挂逼打开了爆头挂" <<endl;
	  Baotou=1;
	  }
	  else
	  {cout<<"挂逼这回合没有开挂"<<endl;
	  }
}
	  round=round+"1";
	  random=sx(h+"round"+round+namet2[ytemp]+"Choice"+seed)*7;
      target=sx(h+"round"+round+namet2[ytemp]+"Target"+seed)%t1n+1;
     c:if (random<=bj2[ytemp]&&bjCD2[ytemp]<=0)
      {
	  if (namet2[ytemp]=="Rinick")
      {cout<<"Rinick使用了神力·必杀之诀,"<<namet1[target]<<"被强行击杀"<<endl;
      if (bld2[ytemp]>=bld1[target]*2/3)
      {cout<<"Rinick自身损失了"<<bld1[target]*2/3<<"点血 "<<endl;
      bld2[ytemp]=bld2[ytemp]-bld1[target]*2/3;
	  }
	  else
	  {cout<<"Rinick神力大损，只剩下一滴血"<<endl;
	  bld2[ytemp]=1;
	  }
	t1n=t1n-harm(1,target,inf*100,t1n,t2n,ytemp);
	goto l1;
	  }
	  
	  Superattack(2,ytemp,t2n);
      if (namet2[ytemp]=="喷气翼龙")
      {t2n++;
	  }
	  }
	  else if (random>100 && random<=tb2[ytemp]+100 && tbCD2[ytemp]<=0)
	  {if (namet2[ytemp]=="Rinick")
	  {cout<<"Rinick发动了NULL值净化"<<endl;
	  cout<<"对方所有反弹盾，吸血盾全部对对方自己造成等量伤害并为自己回血"<<endl;
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
      {cout<<"Rinick运用祂的神力使世界崩坏,";
      cout<<"对手的攻防速血被洗牌"<<endl;
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
	  
	  cout<<"Rinick从时空中汲取神力，将已损失血量一部分化为吸血盾"<<endl;
	  cout<<"Rinick获得了"<<(1536-bld2[ytemp])/6<<"点吸血盾" <<endl;
	  sldn[2][ytemp]=sldn[2][ytemp]+(1536-bld2[ytemp])/6;
}
else
{cout<<"Rinick从空间中汲取神力，将现有血量一部分化为吸血盾"<<endl;
cout<<"Rinick获得了"<<bld2[ytemp]/6<<"点吸血盾"<<endl;
sldn[2][ytemp]=sldn[2][ytemp]+bld2[ytemp]/6;
}
	  goto l1;
	  }
	  Shield(2,ytemp);
	  }
	  	  else if (random>600 && random<=grh[2][ytemp]+600 && grhCD[2][ytemp]<=0)
	  {grhCD[2][ytemp]=4;
	  cout<<namet2[ytemp]<<"发动横扫之刃,对对方全体造成"<<att2[ytemp]/2<<"点伤害"<<endl;
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
	  	{cout<<namet2[ytemp]<<"(血量为"<<bld2[ytemp]<<")"<<"对"<<namet1[target]<<"(血量为"<<bld1[target]<<")"<<"攻击造成"<<att2[ytemp]/2-def1[target]/3+sx(h+"round"+round+namet2[ytemp]+"Fudong"+seed)/10<<"点伤害"<<"，但被闪避了开"<<endl ;
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
	{cout<<"但被"<<namet1[target]<<"反弹了回去"<<endl ;
t2n=t2n-harm(2,ytemp,att2[ytemp]/2-def1[target]/3+sx(h+"round"+round+namet2[ytemp]+"Fudong"+seed)/10,t1n,t2n,target);
mir[1][target]--;
if (t2n<=0)
{return 1;
}
}
}
	}

else
{cout<<namet2[ytemp]<<"(血量为"<<bld2[ytemp]<<")"<<"对"<<namet1[target]<<"(血量为"<<bld1[target]<<")"<<"攻击造成"<<0<<"伤害"<<"......."<<endl;
}
      }
      else
      {if (namet2[ytemp]=="挂逼")
{cout<<"挂逼购买了全服喇叭：“你以为你雷的到你爸爸”"<<endl;
ltnh[2][ytemp]=0; 
goto guabi2;
}
	  cout<<namet2[ytemp]<<"(血量为"<<bld2[ytemp]<<")"<<"被雷击了，一回合不能行动"<<endl;
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
    
    cout<<"攻击力为"<<sx(name+"Attack")<<endl;
	 cout<<"防御力为"<<sx(name+"Defend")<<endl;
	 cout<<"速度为"<<sx(name+"Speed")<<endl;
	 cout<<"血量为"<<sx(name+"Blood")*3<<endl;
	 cout<<"暴击概率"<<sx(name+"Superattack")<<"%"<<endl;
	 cout<<"铁壁概率"<<sx(name+"Superdefend")<<"%"<<endl;
	 cout<<"治疗术概率"<<sx(name+"Cure")<<"%"<<endl;
	 cout<<"雷击术概率"<<sx(name+"Lightning")<<"%"<<endl;
	 cout<<"反伤概率"<<sx(name+"Reflect")<<"%"<<endl;
	 cout<<"吸血魔盾术概率"<<sx(name+"Shield")<<"%"<<endl;
	 cout<<"横扫之刃概率"<<sx(name+"Groupharm")<<"%"<<endl;
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
 
cout<<"1.查看属性"<<endl<<"2.对战"<<endl<<"3.挑战boss"<<endl<<"4.名字评分"<<endl<<"5.胜率测试"<<endl<<"6.内置测号器"<<endl;
cin>>method;
if (method==1)
{SXCK();
}
else if (method==2)
{Gui_or_not=1;
cout<<"输入第一组人数"<<endl;
cin>>team1num;
cout<<"输入第二组人数"<<endl;
cin>>team2num; 
cout<<"输入第一组成员，换行表示一个结束"<<endl;
for (utemp=1;utemp<=team1num;utemp++)
{cin>>namet1[utemp];
}
cout<<"输入第二组成员，换行表示一个结束"<<endl;
for (utemp=1;utemp<=team2num;utemp++)
{cin>>namet2[utemp];
}
cout<<"输入seed"<<endl;
cin>>fseed;
cout<<"输入延迟"<<endl;
cin>>delaym;
if (fight(team1num,team2num,fseed,delaym)==1)
{cout<<"一队赢了！";

}
else
{cout<<"二队赢了！";
}
Gui_or_not=0;
}
else if (method==6)
{cout<<"请输入前缀"<<endl;
cin>>qzm;
int request;
cout<<"请输入测号属性要求(1100满分建议960)" ; 
cin>>request;
int jnum;
cout<<"请输入测号数量";
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
{cout<<"请选择boss"<<endl<<"1.RailGun"<<endl<<"2.喷气翼龙"<<endl<<"3.挂逼"<<endl<<"4.名竞之神---Rinick"<<endl;
int htemp;
cin>>htemp;
if (htemp==1)
{cout<<"输入挑战人数"<<endl;
cin>>bossnum;
cout<<"请依次输入挑战名字"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="RailGun";
if (fight(bossnum,1,"",300)==1)
{cout<<"你赢了！";

}
else
{cout<<"你输了！";
}
  
}

else if (htemp==2)
{cout<<"输入挑战人数"<<endl;
cin>>bossnum;
cout<<"请依次输入挑战名字"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="喷气翼龙";
if (fight(bossnum,1,"",300)==1)
{cout<<"你赢了！";

}
else
{cout<<"你输了！";
}
  
}
else if (htemp==3)
{cout<<"输入挑战人数"<<endl;
cin>>bossnum;
cout<<"请依次输入挑战名字"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="挂逼";
if (fight(bossnum,1,"",300)==1)
{cout<<"你赢了！";

}
else
{cout<<"你输了！";
}
  
}
else if (htemp==4)
{cout<<"输入挑战人数"<<endl;
cin>>bossnum;
cout<<"请依次输入挑战名字"; 
for (utemp=1;utemp<=bossnum;utemp++)
{cin>>namet1[utemp];
}
namet2[1]="Rinick";
if (fight(bossnum,1,"",300)==1)
{cout<<"你赢了！";

}
else
{cout<<"你输了！";
}
  
}
}


else if (method==4)
{cout<<"输入需要测试的号";
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
{cout<<"输入第一队测试人数"<<endl;cin>>tt1n;
cout<<"输入第二队测试人数"<<endl;cin>>tt2n;
cout<<"输入第一队成员"<<endl;
for (ctemp=1;ctemp<=tt1n;ctemp++)
{cin>>op[ctemp];
}
cout<<"输入第二队成员"<<endl;
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
cout<<"第一队赢了"<<winnum<<"/10000"; 
 } 


system("pause");
 
    return 0;
}
