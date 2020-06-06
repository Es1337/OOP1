#include <cmath>
#include <string>

class Towar{
    public:
        virtual ~Towar(){};
        
        virtual double cena() const
        {
            return 0.;
        }
        
        virtual std::string nazwa() const
        {
            return "towar";
        }
};

class Decorator : public Towar
{
  public:
    Decorator(Towar* towar) // Ustalam obiekt dekorowany
    {
        t = towar;
    }
    
    ~Decorator() // Obiekt dekorowany usuniety razem z dekoratorem
    {
        delete t;
    }
    
    double cena()
    {
        return t->cena();
    }
    
    std::string nazwa()
    {
        return t->nazwa();
    }
    
    Towar* t;
};

class Zaokraglenie : public Decorator // Zaokragla w gore do X.99
{
    public:
        Zaokraglenie(Towar* t) : Decorator(t){}
        
        double cena() const
        {
            return std::ceil(t->cena())-0.01;
        }
        
        std::string nazwa() const
        {
            return t->nazwa() + "Zaokraglone w gore: "; 
        }
};

class Marza : public Decorator // Dolicza marze
{
    public:
        Marza(Towar* t, double marza) : Decorator(t), m_marza(marza){}
        
        double cena() const{
            return t->cena()*(1+m_marza);
        }
        
        std::string nazwa() const
        {
            return t->nazwa() + "*Marza: " + std::to_string(m_marza*100) + "% "; 
        }
        
    private:
        double m_marza;
};

class Promocja : public Decorator // Uwzglednienie promocji
{
    public:
        Promocja(Towar* t, double obnizka) : Decorator(t), m_obnizka(obnizka){}
        
        double cena() const
        {
            return t->cena()*(1-m_obnizka);
        }
        
        std::string nazwa() const
        {
            return t->nazwa() + "Na promocji: " + std::to_string(m_obnizka*100) + "% "; 
        }
        
    private:
        double m_obnizka;
};

class OplataStala : public Decorator // Dodawanie oplaty stalej
{
    public:
        OplataStala(Towar* t, double oplata) : Decorator(t), m_oplata(oplata){}
        
        double cena() const
        {
            return t->cena()+m_oplata;
        }
        
        std::string nazwa() const
        {
            return t->nazwa() + "+Oplata stala: " + std::to_string(m_oplata) + " "; 
        }
        
    private:
        double m_oplata;
};