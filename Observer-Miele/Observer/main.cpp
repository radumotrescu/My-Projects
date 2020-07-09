#include <iostream>
#include <memory>
#include <vector>

class Observer
{
public:
    virtual void ShowMyself(const char* color) const = 0;
};

class ObserverHouse : public Observer
{
public:
    ObserverHouse() = default;
    ObserverHouse(const ObserverHouse&) = default;
    ObserverHouse(ObserverHouse&&) = default;

    void ShowMyself(const char* color) const final
    {
        std::cout << "I'm a house and I'm " << color << ".\n";
    }
private:
};

class ObserverWindow : public Observer
{
public:
    ObserverWindow() = default;
    ObserverWindow(const ObserverWindow&) = default;
    ObserverWindow(ObserverWindow&&) = default;

    void ShowMyself(const char* color) const final
    {
        std::cout << "I'm a window and I'm " << color << ".\n";
    }
private:
};

class ObserverCorvette : public Observer
{
public:
    ObserverCorvette() = default;
    ObserverCorvette(const ObserverCorvette&) = default;
    ObserverCorvette(ObserverCorvette&&) = default;

    void ShowMyself(const char* color) const final
    {
        std::cout << "I'm a Corvette and I'm " << color << ".\n";
    }
private:
};

class Painter
{
public:
    Painter() = default;
    Painter(const Painter&) = default;
    Painter(Painter&&) = default;

    void SetColor(const char* color) const
    {
        for (auto observer : m_observers)
            observer->ShowMyself(color);
    };

    void Attach(std::shared_ptr<Observer> observer)
    {
        m_observers.push_back(observer);
    }
    
private:
    std::vector<std::shared_ptr<Observer>> m_observers;
};

int main()
{
    const auto oHouse = std::make_shared<ObserverHouse>();
    const auto oWindow = std::make_shared<ObserverWindow>();
    const auto oCorvette = std::make_shared<ObserverCorvette>();
    auto painter_o = Painter();
    painter_o.Attach(oHouse);
    painter_o.Attach(oWindow);
    painter_o.Attach(oCorvette);

    painter_o.SetColor("blue");
}