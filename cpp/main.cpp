#include <iostream>
#include <array>
#include <exception>

/**
 * A class to represent a movie theater room
 */
class Room {
private:
    // Reserved seats
    std::array<std::array<bool, 9>, 8> seats;   // 8 row of 9 seats
    
    friend std::ostream& operator<<(std::ostream& stream, Room& room);
    
public:
    /**
     * Construct an empty room
     */
    Room() {
        for(auto& row: seats) {
            for(auto& seat: row) {
                seat = false;
            }
        }
    }
    
    /**
     * Get the number of free seats on a row (not contiguous)
     */
    std::size_t get_free_seat_at_row(std::size_t row_id) {
        std::size_t free_seats = 0;
        
        for(const auto& seat: seats[row_id]) {
            if(!seat) ++free_seats;
        }
        
        return free_seats;
    }
    
    /**
     * Book nb_seats seats on row row_id
     */
    void book_seats(std::size_t row_id, std::size_t nb_seats) {
        if(get_free_seat_at_row(row_id) < nb_seats) {
            throw std::logic_error("Il n'y a pas assez de places sur cette rangée !");
        } else {
            for(auto& seat: seats[row_id]) {
                if(nb_seats <= 0) break;
                
                if(seat) {
                    continue;
                } else {
                    seat = true;
                    --nb_seats;
                }
            }
        }
    }
};

std::ostream& operator<<(std::ostream& stream, Room& room) {
    // C++20 is used only here (ranged for loop initializer)
    for(std::size_t i=0; const auto& row: room.seats) {
        stream << i << " | ";
        
        for(const auto& seat: row) {
            stream << (seat?"[ X ]":"[ _ ]");
        }
        
        stream << "\n";
        ++i;
    }
    
    stream << "    ";
    
    for(std::size_t i=0; i < 9; ++i) {
        stream << "  " << i << "  ";
    }
    
    return stream;
}

int main() {
    
    Room room;
    std::size_t nb_seats, row_id;
    
    while(true) {
        std::cout << "Combien de places voulez vous acheter ?\n";
        std::cin >> nb_seats;
        std::cout << "A quelle rangée voulez vous aller ?\n";
        std::cin >> row_id;
    
        std::cout << "\n\n------------------------------\n\n\n";
    
        try {
            room.book_seats(row_id, nb_seats);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        
        std::cout << room << std::endl;
        
        std::cout << "\n\n------------------------------\n\n\n";
    }
    
    return 0;
}
