#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include <time.h>
#define MAX 100005

#define true 1
#define false 0
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

inline Node *createNode(const unsigned int data);

typedef struct Queue
{
    Node *head;
    Node *tail;
} Queue;

inline void push_back(Queue *q, const unsigned int len);

inline void pop_front(Queue *q);

inline unsigned int queue_isEmpty(const Queue *q);

typedef struct Stack
{
    unsigned int array[2 * MAX];
    unsigned int size;
} Stack;

Stack *createStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->size = -1;
    return stack;
}

inline void push(Stack *stack, unsigned int value);
inline void pop(Stack *stack);
inline unsigned int stack_isEmpty(const Stack *stack);

inline unsigned int top(const Stack *stack);
inline unsigned int readInt();
unsigned int *adj_list[MAX];
unsigned int N;
unsigned int len;
unsigned int table[MAX] = {false};
unsigned int ans[15 * MAX] = {0};
unsigned int len_ans = 0;
Queue *q[MAX];
unsigned int temp;
int main()
{
    // double begin = clock();
    setvbuf(stdin, calloc(1 << 26, sizeof(char)), _IOFBF, 1 << 26);
    setvbuf(stdout, calloc(1 << 26, sizeof(char)), _IOFBF, 1 << 26);
    N = readInt();
    Stack *stack = createStack();
    for (unsigned int i = 1; i < N + 1; ++i)
    {
        q[i] = malloc(sizeof(Queue));
        q[i]->head = q[i]->tail = NULL;
        len = readInt();

        // temp = readInt();
        push_back(q[i], len);
    }

    unsigned int i = 1;
    unsigned int from, to;
    while (i <= N)
    {
        if (queue_isEmpty(q[i]) == false)
        {
            push(stack, i);
            table[i] = true;
        }

        while (stack_isEmpty(stack) == false)
        {

            while (queue_isEmpty(q[top(stack)]) == false)
            {
                from = top(stack);
                to = q[from]->head->data;
                if (q[to]->head->data == from)
                {
                    ans[len_ans++] = from;
                    ans[len_ans++] = to;

                    // printf("%d %d\n", from, to);
                    //真的去pop
                    pop_front(q[to]);
                    pop_front(q[from]);

                    if (!stack_isEmpty(stack))
                    {
                        table[from] = false;
                        pop(stack);
                        // flag = true;
                        break;
                    }
                }
                else if (table[to] == true)
                {
                    printf("No\n");
                    return 0;
                }
                else
                {
                    table[to] = true;
                    push(stack, to);
                }
                if (queue_isEmpty(q[top(stack)]) == true)
                    break;
            }
        }
        if (queue_isEmpty(q[i]))
            ++i;
    }
    // printf("Yes\n");
    puts("Yes");
    i = 0;
    for (; i + 200 < len_ans; i += 200)
    {
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",
               ans[i], ans[i + 1],
               ans[i + 2], ans[i + 3],
               ans[i + 4], ans[i + 5],
               ans[i + 6], ans[i + 7],
               ans[i + 8], ans[i + 9],
               ans[i + 10], ans[i + 11],
               ans[i + 12], ans[i + 13],
               ans[i + 14], ans[i + 15],
               ans[i + 16], ans[i + 17],
               ans[i + 18], ans[i + 19],
               ans[i + 20], ans[i + 21],
               ans[i + 22], ans[i + 23],
               ans[i + 24], ans[i + 25],
               ans[i + 26], ans[i + 27],
               ans[i + 28], ans[i + 29],
               ans[i + 30], ans[i + 31],
               ans[i + 32], ans[i + 33],
               ans[i + 34], ans[i + 35],
               ans[i + 36], ans[i + 37],
               ans[i + 38], ans[i + 39],
               ans[i + 40], ans[i + 41],
               ans[i + 42], ans[i + 43],
               ans[i + 44], ans[i + 45],
               ans[i + 46], ans[i + 47],
               ans[i + 48], ans[i + 49],
               ans[i + 50], ans[i + 51],
               ans[i + 52], ans[i + 53],
               ans[i + 54], ans[i + 55],
               ans[i + 56], ans[i + 57],
               ans[i + 58], ans[i + 59],
               ans[i + 60], ans[i + 61],
               ans[i + 62], ans[i + 63],
               ans[i + 64], ans[i + 65],
               ans[i + 66], ans[i + 67],
               ans[i + 68], ans[i + 69],
               ans[i + 70], ans[i + 71],
               ans[i + 72], ans[i + 73],
               ans[i + 74], ans[i + 75],
               ans[i + 76], ans[i + 77],
               ans[i + 78], ans[i + 79],
               ans[i + 80], ans[i + 81],
               ans[i + 82], ans[i + 83],
               ans[i + 84], ans[i + 85],
               ans[i + 86], ans[i + 87],
               ans[i + 88], ans[i + 89],
               ans[i + 90], ans[i + 91],
               ans[i + 92], ans[i + 93],
               ans[i + 94], ans[i + 95],
               ans[i + 96], ans[i + 97],
               ans[i + 98], ans[i + 99],
               ans[i + 100], ans[i + 101],
               ans[i + 102], ans[i + 103],
               ans[i + 104], ans[i + 105],
               ans[i + 106], ans[i + 107],
               ans[i + 108], ans[i + 109],
               ans[i + 110], ans[i + 111],
               ans[i + 112], ans[i + 113],
               ans[i + 114], ans[i + 115],
               ans[i + 116], ans[i + 117],
               ans[i + 118], ans[i + 119],
               ans[i + 120], ans[i + 121],
               ans[i + 122], ans[i + 123],
               ans[i + 124], ans[i + 125],
               ans[i + 126], ans[i + 127],
               ans[i + 128], ans[i + 129],
               ans[i + 130], ans[i + 131],
               ans[i + 132], ans[i + 133],
               ans[i + 134], ans[i + 135],
               ans[i + 136], ans[i + 137],
               ans[i + 138], ans[i + 139],
               ans[i + 140], ans[i + 141],
               ans[i + 142], ans[i + 143],
               ans[i + 144], ans[i + 145],
               ans[i + 146], ans[i + 147],
               ans[i + 148], ans[i + 149],
               ans[i + 150], ans[i + 151],
               ans[i + 152], ans[i + 153],
               ans[i + 154], ans[i + 155],
               ans[i + 156], ans[i + 157],
               ans[i + 158], ans[i + 159],
               ans[i + 160], ans[i + 161],
               ans[i + 162], ans[i + 163],
               ans[i + 164], ans[i + 165],
               ans[i + 166], ans[i + 167],
               ans[i + 168], ans[i + 169],
               ans[i + 170], ans[i + 171],
               ans[i + 172], ans[i + 173],
               ans[i + 174], ans[i + 175],
               ans[i + 176], ans[i + 177],
               ans[i + 178], ans[i + 179],
               ans[i + 180], ans[i + 181],
               ans[i + 182], ans[i + 183],
               ans[i + 184], ans[i + 185],
               ans[i + 186], ans[i + 187],
               ans[i + 188], ans[i + 189],
               ans[i + 190], ans[i + 191],
               ans[i + 192], ans[i + 193],
               ans[i + 194], ans[i + 195],
               ans[i + 196], ans[i + 197],
               ans[i + 198], ans[i + 199]);
    }
    for (; i + 20 < len_ans; i += 20)
    {
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",
               ans[i], ans[i + 1],
               ans[i + 2], ans[i + 3],
               ans[i + 4], ans[i + 5],
               ans[i + 6], ans[i + 7],
               ans[i + 8], ans[i + 9],
               ans[i + 10], ans[i + 11],
               ans[i + 12], ans[i + 13],
               ans[i + 14], ans[i + 15],
               ans[i + 16], ans[i + 17],
               ans[i + 18], ans[i + 19]);
    }
    for (; i < len_ans; i += 2)
    {
        printf("%d %d\n", ans[i], ans[i + 1]);
    }
    // double end = clock();
    // printf("%f\n", (end - begin) / CLOCKS_PER_SEC);
    // printf("%d", len_ans);
    return 0;
}
char c;
unsigned int readInt()
{
    unsigned int num = 0;
    // unsigned int flag = 0;
    c = getchar();
    while ((c < '0' || c > '9'))
    {
        // if (c == '-')
        //     flag = 1;
        c = getchar();
    }
    while (c > ('0' - 1) && c < ('9' + 1))
        num = num * 10 + (c - '0'), c = getchar();
    // if (flag == 0)
    return num;
    // else
    //     return num * (-1);
}

void push_back(Queue *q, const unsigned int len)
{
    for (unsigned int i = len; i--;)
    {
        Node *newNode = createNode(readInt());
        if (q->head == NULL)
            q->head = q->tail = newNode;
        else
        {
            q->tail->next = newNode;
            q->tail = newNode;
        }
    }
}

void pop_front(Queue *q)
{
    if (q->head != NULL)
        q->head = q->head->next;
}

Node *createNode(const unsigned int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

unsigned int queue_isEmpty(const Queue *q)
{
    if (q->head == NULL)
        return true;
    return false;
}

void push(Stack *stack, unsigned int value)
{
    stack->size++;
    stack->array[stack->size] = value;
}

void pop(Stack *stack)
{
    --stack->size;
}

unsigned int stack_isEmpty(const Stack *stack)
{
    return stack->size == -1;
}
unsigned int top(const Stack *stack)
{
    return stack->array[stack->size];
}