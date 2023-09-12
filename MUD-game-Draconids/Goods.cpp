#include "Goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case 0: {
		goodsId = id;
		name = "拳头";
		desc = "平平无奇的拳头";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 5;
		priceBuy = 200;
		priceSell = 50;
		break;
	}

	case 1: {
		goodsId = id;
		name = "巴雷特重型狙击步枪";
		desc = "原为美国巴雷特公司研制的一型大口径狙击步枪";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 0;
		priceSell = 500;
		break;
	}
	case 2: {
		goodsId = id;
		name = "短弧刀";
		desc = "日本分部赠与路明非，灵巧至极";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1200;
		priceSell = 500;
		break;
	}
	case 3: {
		goodsId = id;
		name = "蜘蛛切&童子切安钢";
		desc = "剑源稚生赠与楚子航的两把日本国宝级宝刀";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1400;
		priceSell = 600;
		break;
	}
	case 4: {
		goodsId = id;
		name = "天羽羽斩";
		desc = "传说为须佐之男斩断八岐大蛇的神剑";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1300;
		priceSell = 600;
		break;
	}
	case 5: {
		goodsId = id;
		name = "七宗罪";
		desc = "以七宗罪为名的七把刀剑，需极高的龙血浓度才能拔出";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1200;
		priceSell = 500;
		break;
	}
	case 6: {
		goodsId = id;
		name = "天谴";
		desc = "加图索家族联合俄罗斯联邦航天局共同开发的天基动能武器！！";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1500;
		priceSell = 700;
		break;
	}
	case 7: {
		goodsId = id;
		name = "精钢甲";
		desc = "使用精钢烧制的盔甲,能够有效降低外界的伤害";
		type = 1;
		addDefend = 10;
		addMaxHP = 20;
		//addMaxMP = 10;
		priceBuy = 300;
		priceSell = 90;
		break;
	}
	case 8: {
		goodsId = id;
		name = "环锁铠";
		desc = "由铁丝或铁环套扣缀合成衣状,每环与另四个环相套扣,形如网锁";
		type = 1;
		addDefend = 20;
		addMaxHP = 30;
		//addMaxMP = 30;
		priceBuy = 500;
		priceSell = 200;
		break;
	}
	case 9: {
		goodsId = id;
		name = "金丝软猬甲";
		desc = "用金丝和千年滕枝混合编织而成,柔软且刀枪不入,是一件难得的珍宝";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 10: {
		goodsId = id;
		name = "青云战袍";
		desc = "华丽无比，远观行若流云，更显玉树临风。";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 800;
		priceSell = 370;
		break;
	}
	case 11: {
		goodsId = id;
		name = "天蚕宝甲";
		desc = "用天蚕丝线所织，色泽偏白，质地坚韧，珍贵异常";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 12: {
		goodsId = id;
		name = "金创药";
		desc = "常见的疗伤药,补充少量气血";
		type = 2;
		addHP = 30;
		priceBuy = 0;
		priceSell = 0;
		break;
	}
	case 13: {
		goodsId = id;
		name = "小还丹";
		desc = "散发着香气的紫色药丸,补充大量气血";
		type = 2;
		addHP = 60;
		priceBuy = 110;
		priceSell = 10;
		break;
	}
		   /*case 22: {
			   goodsId = id;
			   name = "定神香";
			   desc = "名贵药物精心炼成的丹药,补充少量内力";
			   type = 2;
			   addMP = 30;
			   priceBuy = 80;
			   priceSell = 10;
			   break;
		   }
		   case 23: {
			   goodsId = id;
			   name = "风水混元丹";
			   desc = "有着浓郁香气的药丸,补充大量内力";
			   type = 2;
			   addMP = 60;
			   priceBuy = 100;
			   priceSell = 15;
			   break;
		   }*/
	default:
		break;
	}
}

Goods::Goods()
{
}

Goods::~Goods()
{
}

string Goods::getDescd() {
	return desc;
}

int Goods::getAddAGI() {
	return addAGI;
}

string Goods::getName() {
	return string(name);
}

int Goods::getGoodsId()
{
	return goodsId;
}

string Goods::getDesc()
{
	return string(desc);
}



int Goods::getType()
{
	return type;
}

int Goods::getAddAttack()
{
	return addAttack;
}

int Goods::getAddDefend()
{
	return addDefend;
}

int Goods::getAddHP()
{
	return addHP;
}

int Goods::getAddMaxHP()
{
	return addMaxHP;
}

int Goods::getPriceSell()
{
	return priceSell;
}

int Goods::getPriceBuy()
{
	return priceBuy;
}

void Goods::showGoods()
{
	cout << name << endl;
	cout << desc << endl;
	if (type == 0) //武器
	{
		cout << "攻击力:" << addAttack << endl;
		cout << "防御力:" << addDefend << endl;
		cout << "敏捷:" << addAGI << endl;

	}
	if (type == 1) //防具
	{
		cout << "防御力:" << addDefend << endl;
		cout << "敏捷:" << addAGI << endl;
		cout << "血量:" << addMaxHP << endl;
	}
	if (type == 2) //药品
	{
		cout << "回复血量:" << addHP << endl;
	}
}
