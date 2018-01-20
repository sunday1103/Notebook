struct storage
{
	uint32_t *fee; //fee 是一个数组，大小为size
	uint32_t flag; // 每一位存储是否有特定邮费,前32个省份
	uint32_t def; //默认fee
	char flag_1； //后两个省份
	char size; //有多少个特定邮费的省份
};

int getIndex(const char *provinceName)
{
	//获取provinceName对应的在flag中的index
	//可以用hash表存储
}

bool isSet(const uint8_t *storage, int k)
{
	//判断是否有特殊邮费
}

uint32_t getFee(int k)
{
	//
}

uint32_t ComputePostFee(const uint8_t *storage, int size, const char *provinceName) 
{
      // Please write your implementation here.
	int k = getIndex(provinceName);
	bool b = isSet(storage,k);
	if (b)
	{
		return getFee(int k);
	}
	else
	{
		return storage.def;
	}
}