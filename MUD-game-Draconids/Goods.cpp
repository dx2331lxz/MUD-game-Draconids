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
		name = "沙漠之鹰·银版";
		desc = "原著中凯撒的标志性武器，后赠与路明非";
		type = 0;
		addAttack = 20;
		addAGI = 3;
		addDefend = 0;
		priceBuy = 400;
		priceSell = 100;
		break;
	}
	case 2: {
		goodsId = id;
		name = "维克推多（“独裁者”）";
		desc = "这把猎刀寄托着加图索家族对凯撒的厚望";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 600;
		priceSell = 200;
		break;
	}
	case 3: {
		goodsId = id;
		name = "妖刀“村雨”";
		desc = "不存于世的刀，楚子航的第一把佩刀";
		type = 0;
		addAttack = 0;
		addDefend = 0;
		addAGI = 0;
		priceBuy = 800;
		priceSell = 400;
		break;
	}
	case 4: {
		goodsId = id;
		name = "巴雷特重型狙击步枪";
		desc = "原为美国巴雷特公司研制的一型大口径狙击步枪";
		type = 0;
		addAttack = 0;
		addAGI = 0;
		addDefend = 0;
		priceBuy = 1000;
		priceSell = 500;
		break;
	}
	case 5: {
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
	case 6: {
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
	case 7: {
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
	case 8: {
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
	case 9: {
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
	case 10: {
		goodsId = id;
		name = "青布衣";
		desc = "普通人家男性所穿的服饰,面料与剪裁都很普通";
		type = 1;
		addDefend = 5;
		addMaxHP = 10;
		//addMaxMP = 0;
		priceBuy = 200;
		priceSell = 70;
		break;
	}
	case 11: {
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
	case 12: {
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
	case 13: {
		goodsId = id;
		name = "冰晶战衣";
		desc = "外表看来宛如透明水晶,实际上却是用千年不化的天山寒冰制成,非常珍贵";
		type = 1;
		addDefend = 30;
		addMaxHP = 40;
		//addMaxMP = 40;
		priceBuy = 700;
		priceSell = 300;
		break;
	}
	case 14: {
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
	case 15: {
		goodsId = id;
		name = "琥珀战甲";
		desc = "以青绿色的琥珀为主、佐以金色琥珀为衬，绿色的肩甲以手工亮片镶成，雕工精细华丽";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 16: {
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
	case 17: {
		goodsId = id;
		name = "云练天衣";
		desc = "外形飘逸轻薄的丝衣，穿在身上仿佛有云气环绕";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 900;
		priceSell = 400;
		break;
	}
	case 18: {
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
	case 19: {
		goodsId = id;
		name = "紫龙天罡铠";
		desc = "传说是由龙气化作紫色鳞片镶嵌而成的战甲，从头到脚绵密包裹";
		type = 1;
		addDefend = 40;
		addMaxHP = 50;
		//addMaxMP = 50;
		priceBuy = 1000;
		priceSell = 450;
		break;
	}
	case 20: {
		goodsId = id;
		name = "金创药";
		desc = "常见的疗伤药,补充少量气血";
		type = 2;
		addHP = 30;
		priceBuy = 90;
		priceSell = 10;
		break;
	}
	case 21: {
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

Goods::~Goods()
{
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