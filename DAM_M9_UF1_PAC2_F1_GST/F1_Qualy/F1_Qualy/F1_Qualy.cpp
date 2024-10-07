#include <iostream>
#include <sqlite3.h>

// Funció per crear la taula de pilots a la base de dades (si no existeix ja)
void creaTaulaPilots(sqlite3* BD) {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS pilots (
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Nom TEXT NOT NULL,
            Equip TEXT NOT NULL,
            PosicioSortida INTEGER NOT NULL,
            TempsPerVolta REAL NOT NULL,
            Voltes INTEGER NOT NULL
        );
    )";

    // Execució de la comanda SQL per crear la taula
    int estat = sqlite3_exec(BD, sql, nullptr, 0, nullptr);
    if (estat != SQLITE_OK) {
        std::cerr << "Compte hi ha hagut un error: " << sqlite3_errmsg(BD) << std::endl;
    }
    else {
        std::cout << "La taula 'pilots' s'ha creat o modificat!" << std::endl;
    }
}

// Registre de les dades dels pilots a la base de dades
void insereixDadesPilots(sqlite3* BD) {
    const char* sql = R"(
        INSERT INTO pilots (Nom, Equip, PosicioSortida, TempsPerVolta, Voltes) VALUES 
        ('George Russell', 'Mercedes', 1, 1.35, 58),
        ('Carlos Sainz', 'Ferrari', 2, 1.36, 58),
        ('Charles Leclerc', 'Ferrari', 3, 1.37, 58);
    )";

    // Execució de la comanda SQL per inserir dades
    int estat = sqlite3_exec(BD, sql, nullptr, 0, nullptr);
    if (estat != SQLITE_OK) {
        std::cerr << "Compte hi ha hagut un error: " << sqlite3_errmsg(BD) << std::endl;
    }
    else {
        std::cout << "Dades dels pilots insertades" << std::endl;
    }
}

int main() {
    sqlite3* BD;

    // Ruta del directori projecte.
    const char* nomBD = "I:/DAM_M9_UF1_PAC2_F1_GST/formula1.db";

    // Accés o denegació del client al fitxer
    if (sqlite3_open(nomBD, &BD) != SQLITE_OK) {
        std::cerr << "No s'ha pogut executar l'accio de crear o modificar la taula a: " << nomBD << std::endl;
        return -1;
    }

    std::cout << "Connexio amb la base de dades OK." << std::endl;

    // Creació de la taula 'pilots' i inserció de les dades
    creaTaulaPilots(BD);
    insereixDadesPilots(BD);

    std::cout << "La base de dades de F1 esta llesta." << std::endl;

    // Sortida de la connexió a la base de dades
    sqlite3_close(BD);
    std::cout << "Resultats registrats!" << std::endl;

    return 0;
}
