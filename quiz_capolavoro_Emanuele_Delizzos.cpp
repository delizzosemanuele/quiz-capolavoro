#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Domanda {
    string materia;
    string testo;
    string opzioni[4];
    int risposta_corretta;
    string spiegazione;
};

const int TOTALE = 24;

Domanda domande[TOTALE] = {
    {
        "ARTE - Le Avanguardie Storiche",
        "Quale movimento fondo il Manifesto nel 1909 esaltando velocita e macchina?",
        {"Dadaismo", "Futurismo", "Cubismo", "Surrealismo"},
        1,
        "Il Futurismo di Marinetti (1909) celebrava modernita, velocita e tecnologia."
    },
    {
        "ARTE - Le Avanguardie Storiche",
        "Il Cubismo e associato principalmente a quale artista?",
        {"Salvador Dali", "Piet Mondrian", "Pablo Picasso", "Marcel Duchamp"},
        2,
        "Picasso e Braque svilupparono il Cubismo scomponendo le forme in piani geometrici."
    },
    {
        "ED. CIVICA - Crans-Montana",
        "Cos'è la pirolisi?",
        {"Una reazione chimica che avviene in presenza di ossigeno", "Un processo di filtrazione dell'acqua", "La decomposizione termica di una sostanza in assenza di ossigeno", "La combustione completa dei rifiuti plastici"},
        2,
        "La pirolisi è la decomposizione chimica di una sostanza organica attraverso il calore, in assenza di ossigeno. Viene usata per trattare rifiuti, biomasse e plastiche, producendo gas, oli e carbone solido."
    },
    {
        "ED. CIVICA - Crans-Montana",
        "A quale temperatura avviene generalmente la pirolisi?",
        {"Tra 20°C e 100°C", "Tra 400°C e 800°C", "Tra 100°C e 200°C", "Oltre i 2000°C"},
        1,
        "La pirolisi avviene tipicamente tra 400°C e 800°C in assenza di ossigeno. Temperature piu' basse favoriscono la produzione di liquidi, quelle più alte la produzione di gas."
    },
    {
        "FILOSOFIA - Nietzsche",
        "Quale concetto indica il superamento dell'uomo verso una forma superiore?",
        {"Eterno ritorno", "Oltreuomo", "Volonta di potenza", "Nichilismo"},
        1,
        "L'Oltreuomo (Uebermensch) crea i propri valori oltre la morale tradizionale."
    },
    {
        "FILOSOFIA - Nietzsche",
        "Con 'Dio e morto' Nietzsche intende che:",
        {"Dio non e mai esistito", "I valori cristiani hanno perso il loro fondamento", "L'ateismo ha vinto", "La scienza ha sconfitto la religione"},
        1,
        "La 'morte di Dio' significa il crollo dei valori morali assoluti dell'Occidente."
    },
    {
        "FISICA - Le Correnti",
        "L'intensita di corrente elettrica si misura in:",
        {"Volt", "Ohm", "Ampere", "Watt"},
        2,
        "L'Ampere (A) misura la quantita di carica che passa in un secondo."
    },
    {
        "FISICA - Le Correnti",
        "La legge di Ohm e:",
        {"V = I + R", "V = I x R", "I = V + R", "R = V + I"},
        1,
        "V = I x R: la tensione e uguale al prodotto tra corrente e resistenza."
    },
    {
        "INFORMATICA - Le Reti",
        "Quanti bit compone un indirizzo IPv4?",
        {"8 bit", "16 bit", "32 bit", "64 bit"},
        2,
        "IPv4 usa 32 bit, scritti come 4 ottetti separati da punti (es. 192.168.1.1)."
    },
    {
        "INFORMATICA - Le Reti",
        "La subnet mask 255.255.255.0 corrisponde in notazione CIDR a:",
        {"/8", "/16", "/24", "/32"},
        2,
        "/24 significa 24 bit dedicati alla rete. 255.255.255.0 ha 24 uni e 8 zeri in binario."
    },
    {
        "ITALIANO - D'Annunzio",
        "D'Annunzio e il massimo esponente italiano di quale corrente?",
        {"Naturalismo", "Verismo", "Estetismo/Decadentismo", "Romanticismo"},
        2,
        "D'Annunzio incarno il Decadentismo: culto della bellezza e vita come opera d'arte."
    },
    {
        "ITALIANO - D'Annunzio",
        "Il romanzo 'Il Piacere' ha come protagonista:",
        {"Mastro-don Gesualdo", "Andrea Sperelli", "Mattia Pascal", "Zeno Cosini"},
        1,
        "Andrea Sperelli e l'alter ego di D'Annunzio: aristocratico, esteta, dominato dai sensi."
    },
    {
        "INGLESE - Victorian Age",
        "The Victorian Age corresponds to the reign of:",
        {"Queen Elizabeth I", "Queen Victoria (1837-1901)", "King George III", "King Edward VII"},
        1,
        "The Victorian Age (1837-1901): industrial growth, empire expansion, moral strictness."
    },
    {
        "INGLESE - Victorian Age",
        "What was the main social problem addressed by Victorian literature?",
        {"Religious conflicts", "Colonial independence", "Industrial poverty and social inequality", "Women's right to vote"},
        2,
        "Victorian literature, especially through authors like Charles Dickens, exposed the harsh conditions of the working class and the growing gap between rich and poor caused by the Industrial Revolution."
    },
    {
        "MATEMATICA - Derivate",
        "Qual e la derivata di f(x) = x^3?",
        {"x^2", "3x^2", "3x", "x^4/4"},
        1,
        "Regola delle potenze: d/dx(x^n) = n*x^(n-1). Quindi d/dx(x^3) = 3x^2."
    },
    {
        "MATEMATICA - Derivate",
        "Qual e la derivata di f(x) = sin(x)?",
        {"cos(x)", "-cos(x)", "-sin(x)", "tan(x)"},
        0,
        "La derivata del seno e il coseno: d/dx(sin x) = cos x."
    },
    {
        "RELIGIONE - Patti Lateranensi",
        "In quale anno furono firmati i Patti Lateranensi?",
        {"1922", "1929", "1936", "1948"},
        1,
        "Firmati l'11 febbraio 1929 tra Mussolini e il cardinale Gasparri per la Santa Sede."
    },
    {
        "RELIGIONE - Patti Lateranensi",
        "I Patti riconoscevano la sovranita della Santa Sede su:",
        {"Roma", "Citta del Vaticano", "Lazio", "Tutta Italia"},
        1,
        "L'Italia riconobbe il Vaticano come Stato sovrano, risolvendo la Questione Romana."
    },
    {
        "SCIENZE MOTORIE - HIV",
        "L'HIV attacca principalmente quale tipo di cellule?",
        {"Globuli rossi", "Linfociti T CD4+", "Piastrine", "Neutrofili"},
        1,
        "L'HIV distrugge i linfociti T CD4+, compromettendo l'immunita fino all'AIDS."
    },
    {
        "SCIENZE MOTORIE - HIV",
        "L'HIV si trasmette attraverso:",
        {"Aria e starnuti", "Contatto con superfici", "Sangue, rapporti non protetti, latte materno", "Punture di insetti"},
        2,
        "L'HIV si trasmette via fluidi corporei: sangue, liquido seminale, secrezioni vaginali, latte materno."
    },
    {
        "SCIENZE - Il DNA",
        "La molecola del DNA ha una struttura a:",
        {"Elica singola", "Doppia elica", "Tripla elica", "Struttura piana"},
        1,
        "Watson e Crick (1953) descrissero la doppia elica del DNA, tenuta da legami idrogeno."
    },
    {
        "SCIENZE - Il DNA",
        "Quali basi azotate si appaiano nel DNA?",
        {"A-G e C-T", "A-T e G-C", "A-C e G-T", "A-U e G-C"},
        1,
        "Adenina-Timina (2 legami H) e Guanina-Citosina (3 legami H). Regola di Chargaff."
    },
    {
        "STORIA - Seconda Guerra Mondiale",
        "In quale anno scoppio la Seconda Guerra Mondiale?",
        {"1937", "1938", "1939", "1940"},
        2,
        "La WWII inizio il 1 settembre 1939 con l'invasione nazista della Polonia."
    },
    {
        "STORIA - Seconda Guerra Mondiale",
        "Chi era il cancelliere della Germania nazista durante la Seconda Guerra Mondiale?",
        {"Heinrich Himmler", "Adolf Hitler", "Hermann Goring", "Joseph Goebbels"},
        1,
        "Adolf Hitler fu cancelliere dal 1933 e Führer dal 1934 fino alla sua morte il 30 aprile 1945. Himmler, Göring e Goebbels erano gerarchi nazisti di primo piano, ma non a capo del governo."
    }
};

void stampa_linea(char c, int n) {
    for (int i = 0; i < n; i++) cout << c;
    cout << "\n";
}

void mescola(int ordine[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = ordine[i];
        ordine[i] = ordine[j];
        ordine[j] = tmp;
    }
}

int main() {
    srand(time(0));
    system("cls");

    stampa_linea('=', 60);
    cout << "      QUIZ CAPOLAVORO - Anno Scolastico 2025/26\n";
    cout << "         12 materie | 24 domande | Buona fortuna!\n";
    stampa_linea('=', 60);
    cout << "\nPremi INVIO per iniziare...";
    cin.get();

    int ordine[TOTALE];
    for (int i = 0; i < TOTALE; i++) ordine[i] = i;
    mescola(ordine, TOTALE);

    int punteggio = 0;
    bool risultati[TOTALE];

    for (int i = 0; i < TOTALE; i++) {
        system("cls");
        Domanda& d = domande[ordine[i]];

        stampa_linea('=', 60);
        cout << "  Domanda " << (i+1) << " di " << TOTALE
             << "   |   Punteggio: " << punteggio << "/" << i << "\n";
        stampa_linea('=', 60);

        cout << "\n[ " << d.materia << " ]\n\n";
        cout << d.testo << "\n\n";

        for (int j = 0; j < 4; j++) {
            cout << "  " << (j+1) << ") " << d.opzioni[j] << "\n";
        }

        int scelta = 0;
        cout << "\nRisposta (1-4): ";
        while (!(cin >> scelta) || scelta < 1 || scelta > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Inserisci un numero tra 1 e 4: ";
        }
        scelta--;

        stampa_linea('-', 60);

        if (scelta == d.risposta_corretta) {
            punteggio++;
            risultati[i] = true;
            cout << "\n  >> CORRETTO! Ottimo lavoro.\n";
        } else {
            risultati[i] = false;
            cout << "\n  >> SBAGLIATO! La risposta corretta era:\n";
            cout << "     " << d.opzioni[d.risposta_corretta] << "\n";
        }

        cout << "\n  Spiegazione: " << d.spiegazione << "\n";
        cout << "\nPremi INVIO per continuare...";
        cin.ignore(1000, '\n');
        cin.get();
    }

    // Risultati finali
    system("cls");
    stampa_linea('=', 60);
    cout << "                  RISULTATI FINALI\n";
    stampa_linea('=', 60);

    int percentuale = (punteggio * 100) / TOTALE;
    cout << "\n  Punteggio:   " << punteggio << " / " << TOTALE << "\n";
    cout << "  Percentuale: " << percentuale << "%\n\n";

    if (percentuale >= 90)
        cout << "  Valutazione: ECCELLENTE - Complimenti!\n";
    else if (percentuale >= 75)
        cout << "  Valutazione: BUONO - Qualche lacuna, ma stai bene.\n";
    else if (percentuale >= 60)
        cout << "  Valutazione: SUFFICIENTE - Ripassa le materie con errori.\n";
    else
        cout << "  Valutazione: INSUFFICIENTE - Continua a studiare!\n";

    stampa_linea('-', 60);
    cout << "\n  Dettaglio domande:\n\n";
    for (int i = 0; i < TOTALE; i++) {
        cout << "  [" << (risultati[i] ? "OK" : "XX") << "] "
             << domande[ordine[i]].materia << "\n";
    }

    stampa_linea('=', 60);
    cout << "\nGrazie! Premi INVIO per uscire...";
    cin.get();

    return 0;
}
