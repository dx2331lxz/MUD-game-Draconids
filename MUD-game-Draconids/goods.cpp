#include "Goods.h"

Goods::Goods(int id)
{
	switch (id)
	{
	case 0: {
		goodsId = id;
		name = "ȭͷ";
		desc = "ƽƽ�����ȭͷ";
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
		name = "ɳĮ֮ӥ������";
		desc = "ԭ���п����ı�־��������������·����";
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
		name = "ά���ƶࣨ�������ߡ���";
		desc = "����Ե������ż�ͼ������Կ����ĺ���";
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
		name = "���������ꡱ";
		desc = "���������ĵ������Ӻ��ĵ�һ���嵶";
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
		name = "���������;ѻ���ǹ";
		desc = "ԭΪ���������ع�˾���Ƶ�һ�ʹ�ھ��ѻ���ǹ";
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
		name = "�̻���";
		desc = "�ձ��ֲ�����·���ǣ���������";
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
		name = "֩����&ͯ���а���";
		desc = "��Դ����������Ӻ��������ձ�����������";
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
		name = "������ն";
		desc = "��˵Ϊ����֮��ն�ϰ�᪴��ߵ���";
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
		name = "������";
		desc = "��������Ϊ�����߰ѵ������輫�ߵ���ѪŨ�Ȳ��ܰγ�";
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
		name = "��Ǵ";
		desc = "��ͼ���������϶���˹�����ֹ�ͬ���������������������";
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
		name = "�಼��";
		desc = "��ͨ�˼����������ķ���,��������ö�����ͨ";
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
		name = "���ּ�";
		desc = "ʹ�þ������ƵĿ���,�ܹ���Ч���������˺�";
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
		name = "������";
		desc = "����˿�������׿�׺�ϳ���״,ÿ�������ĸ������׿�,��������";
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
		name = "����ս��";
		desc = "���������͸��ˮ��,ʵ����ȴ����ǧ�겻������ɽ�����Ƴ�,�ǳ����";
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
		name = "��˿��⬼�";
		desc = "�ý�˿��ǧ����֦��ϱ�֯����,�����ҵ�ǹ����,��һ���ѵõ��䱦";
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
		name = "����ս��";
		desc = "������ɫ������Ϊ�������Խ�ɫ����Ϊ�ģ���ɫ�ļ�����ֹ���Ƭ��ɣ��񹤾�ϸ����";
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
		name = "����ս��";
		desc = "�����ޱȣ�Զ���������ƣ����������ٷ硣";
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
		name = "��������";
		desc = "����Ʈ���ᱡ��˿�£��������Ϸ·�����������";
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
		name = "��ϱ���";
		desc = "�����˿����֯��ɫ��ƫ�ף��ʵؼ��ͣ�����쳣";
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
		name = "���������";
		desc = "��˵��������������ɫ��Ƭ��Ƕ���ɵ�ս�ף���ͷ�������ܰ���";
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
		name = "��ҩ";
		desc = "����������ҩ,����������Ѫ";
		type = 2;
		addHP = 30;
		priceBuy = 90;
		priceSell = 10;
		break;
	}
	case 21: {
		goodsId = id;
		name = "С����";
		desc = "ɢ������������ɫҩ��,���������Ѫ";
		type = 2;
		addHP = 60;
		priceBuy = 110;
		priceSell = 10;
		break;
	}
	/*case 22: {
		goodsId = id;
		name = "������";
		desc = "����ҩ�ﾫ�����ɵĵ�ҩ,������������";
		type = 2;
		addMP = 30;
		priceBuy = 80;
		priceSell = 10;
		break;
	}
	case 23: {
		goodsId = id;
		name = "��ˮ��Ԫ��";
		desc = "����Ũ��������ҩ��,�����������";
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

int Goods::getDescd() {
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
	if (type == 0) //����
	{
		cout << "������:" << addAttack << endl;
		cout << "������:" << addDefend << endl;
		cout << "����:" << addAGI << endl;

	}
	if (type == 1) //����
	{
		cout << "������:" << addDefend << endl;
		cout << "����:" << addAGI << endl;
		cout << "Ѫ��:" << addMaxHP << endl;
	}
	if (type == 2) //ҩƷ
	{
		cout << "�ظ�Ѫ��:" << addHP << endl;
	}
}
