#ifndef COMMAND_H
#define COMMAND_H

 enum Status {
    PENDING,
    EXECUTED,
    UNDONE
 };

class Command {
protected:
    Status status;
    int executionCount;
public:
    Command();

    virtual ~Command() = default;

    virtual void execute() = 0;
    void executed();

    virtual void undo();

    virtual void redo();

    Status getStatus() const;
    int getExecutionCount() const;

};

#endif // COMMAND_H
