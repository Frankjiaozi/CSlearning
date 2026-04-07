#include <stdio.h>
#include <ctype.h>

struct stack
{
    int top;
    int data[100];
};

typedef struct stack stack;

// 你的原有函数：入栈
void push(stack *stack, int num)
{
    stack->top++;
    stack->data[stack->top] = num;
}

// 你的原有函数：出栈
int pop(stack *stack)
{
    int val = stack->data[stack->top];
    stack->top--;
    return val;
}

// 你的原有函数：初始化栈
void initstack(stack *stack)
{
    stack->top = -1;
}

// 你的原有函数：读取多位数
int getnum(char str[], int *pos)
{
    int num = 0;
    while (isdigit(str[*pos]))
    {
        num = num * 10 + (str[*pos] - '0');
        (*pos)++;
    }
    return num;
}

// ===================== 新增通用工具函数 =====================
// 获取运算符优先级 (*/优先级2，+-优先级1)
int priority(char op)
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // ( 优先级最低
}

// 通用计算函数：弹出两个数 + 一个运算符，计算结果
void calc(stack *num_stack, stack *op_stack)
{
    int b = pop(num_stack);   // 后入栈的数
    int a = pop(num_stack);   // 先入栈的数
    char op = pop(op_stack);  // 运算符

    int res;
    switch(op)
    {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
        default: res = 0;
    }
    push(num_stack, res); // 结果放回数字栈
}

// ===================== 主函数（通用逻辑） =====================
int main()
{
    char exp[100];
    int pos = 0;
    scanf("%s", exp);

    stack num_stack;  // 数字栈
    stack op_stack;   // 运算符栈
    initstack(&num_stack);
    initstack(&op_stack);

    while (exp[pos] != '\0')
    {
        if (exp[pos] == ' ') // 跳过空格（兼容带空格的输入）
        {
            pos++;
        }
        // 1. 左括号：直接入运算符栈
        else if (exp[pos] == '(')
        {
            push(&op_stack, exp[pos]);
            pos++;
        }
        // 2. 右括号：一直计算，直到遇到左括号
        else if (exp[pos] == ')')
        {
            while (op_stack.data[op_stack.top] != '(')
            {
                calc(&num_stack, &op_stack);
            }
            pop(&op_stack); // 弹出左括号 ( 丢弃
            pos++;
        }
        // 3. 数字：直接入数字栈
        else if (isdigit(exp[pos]))
        {
            int num = getnum(exp, &pos);
            push(&num_stack, num);
        }
        // 4. 运算符：处理优先级，高优先级先计算
        else
        {
            // 栈顶运算符优先级 ≥ 当前运算符，先计算
            while (op_stack.top != -1 && priority(op_stack.data[op_stack.top]) >= priority(exp[pos]))
            {
                calc(&num_stack, &op_stack);
            }
            push(&op_stack, exp[pos]); // 当前运算符入栈
            pos++;
        }
    }

    // 最后：把剩下的所有运算符全部计算完
    while (op_stack.top != -1)
    {
        calc(&num_stack, &op_stack);
    }

    // 数字栈最后只剩结果
    printf("%d", pop(&num_stack));
    return 0;
}