class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> operands;

        for (char c : expression) {
            if (c == 't' || c == 'f') {
                operands.push(c);
            } 
            else if (c == '&' || c == '|' || c == '!') {
                operators.push(c);
            } 
            else if (c == ')') {
                char op = operators.top();
                operators.pop();
                
                int trueCount = 0, falseCount = 0;
                
                while (operands.top() != '(') {
                    char operand = operands.top();
                    operands.pop();
                    if (operand == 't') trueCount++;
                    else falseCount++;
                }
                
                operands.pop();

                if (op == '&') {
                    operands.push(falseCount > 0 ? 'f' : 't');
                } 
                else if (op == '|') {
                    operands.push(trueCount > 0 ? 't' : 'f');
                } 
                else if (op == '!') {
                    operands.push(falseCount > 0 ? 't' : 'f');
                }
            } 
            else if (c == '(') {
                operands.push(c);
            }
        }

        return operands.top() == 't';
    }
};
