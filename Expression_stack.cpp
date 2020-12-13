// a) Implement stack ADT using linked list. 
// b)Write a program for Expression Evaluation using stack.
// c) Write a program for Expression Conversion using stack.

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/*CHAR STACK CLASS WITH OPERATIONS */
class stack
{
    struct node //Character data node
    {
        char data;
        struct node *next;
    } * top;

public:
    char topstk();
    stack();
    void push(char element);
    char pop();
    int isempty();
    ~stack();
};

/*######## FUCNTIONS FOR STACK ########*/

stack ::stack() //Default Constructor
{
    top = NULL;
}
int stack ::isempty() //To check if stack is empty
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

char stack ::topstk() //To check value of top element of stack
{
    char temp;
    if (isempty() == 1)
        return -1;
    else
    {

        temp = top->data;
        return temp;
    }
}

void stack ::push(char element) // Push fucntion
{
    struct node *newnode = new struct node;
    newnode->data = element;
    if (top == NULL)
    {
        top = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
char stack ::pop() //Pop function
{
    char element;
    if (isempty() == 1)
    {
        cout << "Stack Empty! Cannot Pop..Stack Underflow\n";
        return NULL;
    }
    else
    {
        element = top->data;
        node *temp = top;
        top = top->next;
        delete temp;

        return element;
    }
}
stack::~stack() //Destructor
{
    while (isempty() != 1)
    {
        pop();
    }
}
/*######## INTEGER STACK CLASS WITH OPERATIONS ########*/
class Istack
{
    struct node
    {
        int data; //Integer data node
        struct node *next;
    } * top;

public:
    int Itopstk();
    Istack();
    void Ipush(int element);
    int Ipop();
    int Iisempty();
};

/*######### FUCNTIONS FOR STACK #########*/

Istack ::Istack() //Default Constructor
{
    top = NULL;
}

int Istack ::Iisempty() //To check if stack is empty
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int Istack ::Itopstk() //To check value of top element of stack
{
    int temp;
    temp = top->data;
    return temp;
}

void Istack ::Ipush(int element) // Push fucntion
{
    struct node *newnode = new struct node;
    newnode->data = element;
    if (top == NULL)
    {
        top = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

int Istack ::Ipop() //Pop function
{
    int element;
    if (Iisempty() == 1)
    {
        cout << "Stack Empty! Cannot Pop..Stack Underflow\n";
        return NULL;
    }
    else
    {
        element = top->data;
        node *temp = top;
        top = top->next;
        delete temp;

        return element;
    }
}


/*######## EXPRESSION CLASS ########*/
class expression
{
    char infix[20];
    char postfix[20];
    char prefix[20];
    stack stk;

public:
    void ConvIntoPost();
    void ConvIntoPre();
    expression();
    int precedence(char opt);
    void displaypost();
    void displaypre();
    int evaluatepost();
    int calculate(int, int, char);
    int evaluatepre();
};

/*######### FUCNTIONS OF EXPRESSION CLASS #########*/
expression ::expression() //Constructor
{
    cout << "Enter The Expression of Infix form\n";
    cin >> infix;
}

int expression ::precedence(char opt) //To check precedence of the operators
{
    // if(opt=='(')
    //return 4;
    if (opt == '/' || opt == '*' || opt == '$' || opt == '%')
        return 2;
    if (opt == '+' || opt == '-')
        return 1;
    return 0;
}

void expression ::ConvIntoPost() //To convert infix to postfix
{
    char element, x;
    int i, j = 0;
    //stk.push('(');      //to solve for expressions without brackets
    for (i = 0; i < strlen(infix); i++)
    {
        element = infix[i];

        if (isalnum(element) != 0) //check if it is operand
        {
            postfix[j++] = infix[i];
        }
        else
        {
            if (element == '(') //if opening bracket push on stack
            {
                stk.push(element);
            }

            else
            {
                if (element == ')')
                {
                    while (stk.topstk() != '(')
                    {
                        postfix[j++] = stk.pop();
                    }
                } //check preccedence of operators
                else
                {
                    while ((precedence(element) < precedence(stk.topstk())) && stk.isempty() != 1)
                    {
                        x = stk.pop();
                        if (x != '(' && x != ')')
                            postfix[j++] = x;
                    }
                    if (element != '(' && element != ')') //to check for any stray brackets
                        stk.push(element);
                }
            }
        }
    }

    while (stk.isempty() != 1) //to pop remaining elements of stack
    {
        x = stk.pop();
        if (x != '(' && x != ')')
            postfix[j++] = x;
    }

    postfix[j] = '\0';
}

void expression ::displaypost() //To display postfix expression
{
    cout << "Infix Expression\n";
    cout << infix << "\n";
    cout << "Postfix Expression\n";
    cout << postfix << "\n";
}

void expression ::displaypre() //To display prefix expression
{
    cout << "Infix Expression\n";
    cout << infix << "\n";
    cout << "Prefix Expression\n";
    cout << prefix << "\n";
}

void expression::ConvIntoPre() //To convert infix to postfix
{
    stack prestack, opstack;
    int i, len;
    char element, temp;

    //opstack.push(')');      //to solve expressions without brackets

    len = strlen(infix);

    for (i = len - 1; i >= 0; i--)
    {
        element = infix[i];
        cout << element;
        if (element == ')') //check if it is bracket
        {
            opstack.push(element);
        }
        else if (element == '(') //push the opeartors inside brackets to prestack
        {
            while (opstack.topstk() != ')')
            {
                temp = opstack.pop();
                if (temp != '(')
                    prestack.push(temp);
            }
        }
        else
        {
            if (isalnum(element) != 0)
            {
                prestack.push(element); //to check if it is operand
            }
            else
            {
                //if(opstack.isempty()==1)
                //{
                // opstack.push(element);
                //}

                //else
                //{                                  //check preccedence of operators
                while (precedence(opstack.topstk()) > precedence(element) && !opstack.isempty())
                {
                    temp = opstack.pop();

                    if (temp != ')')
                        prestack.push(temp);
                }
                //}
                opstack.push(element);
            }
        }
    }

    while (opstack.isempty() != 1) //check for remaining elements on stack
    {
        temp = opstack.pop();
        if (temp != '(' && temp != ')')
            prestack.push(temp);
    }

    i = 0;
    while (prestack.isempty() != 1)
    { //insert elements for prestack to array
        prefix[i++] = prestack.pop();
    }

    prefix[i] = '\0';
}

int expression::calculate(int a, int b, char op)
{
    if (op == '+') //To calculate the value of the pair of operands
        return a + b;

    if (op == '-')
        return a - b;
    if (op == '/')
        return a / b;

    if (op == '%')
        return a % b;
    if (op == '*')
        return a * b;
    else
        return 0;
}

int expression ::evaluatepost() //To evaluate postfix expression
{
    int i, value, operator1, operator2, ans;
    char element;
    Istack eval;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        element = postfix[i];

        if (isalnum(element) != 0) //if operand accept value of it and push on integer stack
        {
            cout << "Enter value for operand: " << element << endl;
            cin >> value;
            eval.Ipush(value);
        }
        else //if operator then pop two operands and calculate the value
        {
            operator1 = eval.Ipop();
            operator2 = eval.Ipop();
            ans = calculate(operator2, operator1, element);
            eval.Ipush(ans);
        }
    }
    ans = eval.Ipop();
    return ans;
}

int expression ::evaluatepre() //To evaluate prefix expression
{
    int i, value, operator1, operator2, ans, length;
    char element;
    Istack eval;

    length = strlen(prefix);
    for (i = length - 1; i > 0; i++)
    {
        element = postfix[i];

        if (isalnum(element) != 0) //if operand accept value of it and push on integer stack
        {
            cout << "Enter value for operand: " << element << endl;
            cin >> value;
            eval.Ipush(value);
        }
        else //if operator then pop two operands and calculate the value
        {
            operator2 = eval.Ipop();
            operator1 = eval.Ipop();
            ans = calculate(operator2, operator1, element);
            eval.Ipush(ans);
        }
    }

    ans = eval.Ipop();
    return ans;
}

/*########## MAIN FUNCTION ##########*/
int main()
{
    int opt, result;
    expression exp;
    do
    {
        cout << "\n\nSTACK IMPLEMENTATION\n";
        cout << "Enter Your Choice\n"
             << "1.Convert Infix to Postfix\n"
             << "2.Convert Infix to Prefix\n";
        cout << "3.Evaluate postfix\n"
             << "4.Evaluate prefix\n"
             << "5.EXIT\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            exp.ConvIntoPost();
            exp.displaypost();
            break;
        case 2:
            exp.ConvIntoPre();
            exp.displaypre();
            break;
        case 3:
            result = exp.evaluatepost();
            cout << "Answer of given postfix equation is:-\n"
                 << result;
            break;
        case 4:
            result = exp.evaluatepost();
            cout << "Answer of given postfix equation is:-\n"
                 << result;
            break;
        }
    } while (opt != 5);
    return 0;
}

