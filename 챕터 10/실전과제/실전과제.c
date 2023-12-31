#include <stdio.h>

typedef struct point {
	int x, y;
} POINT;

typedef struct rect {
	int left, top, right, bottom;
} RECT;

void Swap(int* x, int* y);
void PrintRect(const char* title, const RECT* rt);
int NormalizeRect(RECT* rt);
int IsPointInRect(POINT* pt, RECT* rt);

int main(void)
{
	RECT rect1 = { 0 };
	POINT pt;

	printf("좌상단점/우하단점의 좌표를 입력하세요(left, top, right, bottom 순)\n");
	scanf("%d %d %d %d", &rect1.left, &rect1.top, &rect1.right, &rect1.bottom);

	PrintRect("입력된 직사각형", &rect1);
	if (NormalizeRect(&rect1))
	{
		PrintRect("정규화된 직사각형", &rect1);
	}

	printf("한 점의 좌표를 입력하세요(x, y) : ");
	scanf("%d %d", &pt.x, &pt.y);

	printf("(%d, %d)는 ", pt.x, pt.y);
	if (IsPointInRect(&pt, &rect1))
		printf("직사각형 내부에 있습니다.\n");
	else
		printf("직사각형 외부에 있습니다.\n");

	return 0;
}

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void PrintRect(const char* title, const RECT* rt)
{
	printf("%s : 좌상단점=(%d,%d), 우하단점=(%d,%d)\n", title, rt->left, rt->top, rt->right, rt->bottom);
}

int NormalizeRect(RECT* rt)
{
	int result = 0;
	if (rt->left > rt->right)
	{
		Swap(&rt->left, &rt->right);
		result = 1;
	}
	if (rt->top > rt->bottom)
	{
		Swap(&rt->top, &rt->bottom);
		result;
	}
	return result;
}

int IsPointInRect(POINT* pt, RECT* rt)
{
	if (rt->left <= pt->x && pt->x <= rt->right && rt->top <= pt->y && pt->y <= rt->bottom)
		return 1;
	else
		return 0;
}