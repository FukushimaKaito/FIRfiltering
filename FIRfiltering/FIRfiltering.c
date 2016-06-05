/*---------------------------------
FIRフィルタリングプログラム

5I30　福嶋開人
--------------------------------*/
//セキュリティ系Errorを無効化
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("FIRフィルタリングプログラム\n");
	FILE *fpr;
	int i;
	int NumIN, NumH; 		/* データの個数 */
	double *dat, *h;	/* データ配列の先頭アドレス,フィルタ配列の先頭アドレス */


	/*入力信号ファイルの取得*/
	if ((fpr = fopen("signal.txt", "r")) == NULL){
		fprintf(stderr, "信号ファイルをopenできません。\n");
		exit(1);
	}

	fscanf(fpr, "%d", &NumIN);  /* データの個数取得 */
	if ((dat = (double *)malloc(NumIN*sizeof(double))) == NULL)
	{
		fprintf(stderr, "datメモリの確保に失敗しました。\n");
		exit(1);
	}
	for (i = 0; i < NumIN; i++)/* 係数読み込み */
	{
		fscanf(fpr, "%lf", &dat[i]);
	}
	fclose(fpr);

	/*フィルタファイルの取得*/
	if ((fpr = fopen("h23.txt", "r")) == NULL){
		fprintf(stderr, "フィルタファイルをopenできません。\n");
		exit(1);
	}
	fscanf(fpr, "%d", &NumH);  /* データの個数取得 */
	if ((h = (double *)malloc(NumH*sizeof(double))) == NULL)
	{
		fprintf(stderr, "hメモリの確保に失敗しました。\n");
		exit(1);
	}
	for (i = 0; i < NumH; i++)/* 係数読み込み */
	{
		fscanf(fpr, "%lf", &h[i]);
	}
	fclose(fpr);

	/*データ処理*/
	for (int i = 0; i < NumIN; i++)
	{
		for (int j = 0; j < NumH; j++)
		{
			dat[i + j] += h[j] * dat[i];
		}
	}

	for (i = 0; i < NumIN; i++){      /* 読み込んだ値を表示*/
		printf("%d	%23.15e\n", i, dat[i]); /* 小数点以下15桁 */
	}
	return 0;
}