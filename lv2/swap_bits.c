unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	result = 0;
	int	i;
	int	j;
	int	k;

	i = 7;
	j = 8;
	k = 0;
	result = NULL;
	while(4 <= i)
	{
		j--;
		k = ((octet >> i) & 1);
		result[j] = k;
		i--;
	}
	j = 0;
	while(i >= 0)
	{
		k = ((octet >> i) & 1);
		result[j] = k;
		i--;
		j++;
	}
	return(result);
}

unsigned char swap_bits(unsigned char octet)
{
    unsigned char result = 0; // 空の箱（8ビットすべて0）を用意する
    int i;

    // 1. 上位4ビット（7,6,5,4番目）を、下位（3,2,1,0番目）へ移動
    for (i = 7; i >= 4; i--) {
        // octetのi番目のビットを取り出す
        int bit = (octet >> i) & 1; 
        // 4マス右にずらした位置に合体させる
        result |= (bit << (i - 4)); 
    }

    // 2. 下位4ビット（3,2,1,0番目）を、上位（7,6,5,4番目）へ移動
    for (i = 3; i >= 0; i--) {
        // octetのi番目のビットを取り出す
        int bit = (octet >> i) & 1; 
        // 4マス左にずらした位置に合体させる
        result |= (bit << (i + 4)); 
    }

    return (result);
}
