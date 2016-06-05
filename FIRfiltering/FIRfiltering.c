/*---------------------------------
FIR�t�B���^�����O�v���O����

5I30�@�����J�l
--------------------------------*/
//�Z�L�����e�B�nError�𖳌���
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("FIR�t�B���^�����O�v���O����\n");
	FILE *fpr;
	int i;
	int NumIN, NumH; 		/* �f�[�^�̌� */
	double *dat, *h;	/* �f�[�^�z��̐擪�A�h���X,�t�B���^�z��̐擪�A�h���X */


	/*���͐M���t�@�C���̎擾*/
	if ((fpr = fopen("signal.txt", "r")) == NULL){
		fprintf(stderr, "�M���t�@�C����open�ł��܂���B\n");
		exit(1);
	}

	fscanf(fpr, "%d", &NumIN);  /* �f�[�^�̌��擾 */
	if ((dat = (double *)malloc(NumIN*sizeof(double))) == NULL)
	{
		fprintf(stderr, "dat�������̊m�ۂɎ��s���܂����B\n");
		exit(1);
	}
	for (i = 0; i < NumIN; i++)/* �W���ǂݍ��� */
	{
		fscanf(fpr, "%lf", &dat[i]);
	}
	fclose(fpr);

	/*�t�B���^�t�@�C���̎擾*/
	if ((fpr = fopen("h23.txt", "r")) == NULL){
		fprintf(stderr, "�t�B���^�t�@�C����open�ł��܂���B\n");
		exit(1);
	}
	fscanf(fpr, "%d", &NumH);  /* �f�[�^�̌��擾 */
	if ((h = (double *)malloc(NumH*sizeof(double))) == NULL)
	{
		fprintf(stderr, "h�������̊m�ۂɎ��s���܂����B\n");
		exit(1);
	}
	for (i = 0; i < NumH; i++)/* �W���ǂݍ��� */
	{
		fscanf(fpr, "%lf", &h[i]);
	}
	fclose(fpr);

	/*�f�[�^����*/
	for (int i = 0; i < NumIN; i++)
	{
		for (int j = 0; j < NumH; j++)
		{
			dat[i + j] += h[j] * dat[i];
		}
	}

	for (i = 0; i < NumIN; i++){      /* �ǂݍ��񂾒l��\��*/
		printf("%d	%23.15e\n", i, dat[i]); /* �����_�ȉ�15�� */
	}
	return 0;
}