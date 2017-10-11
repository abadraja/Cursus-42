import Foundation

class Deck : NSObject
{
	static let AllSpades : [Card] = Value.allValues.map ({
		return Card(color: .Spades, value: $0)
	})
	static let AllDiamonds : [Card] = Value.allValues.map ({
		return Card(color: .Diamons, value: $0)
	})
	static let AllHearts : [Card] = Value.allValues.map ({
		return Card(color: .Hearts, value: $0)
	})
	static let AllClubs : [Card] = Value.allValues.map ({
		return Card(color: .Clubs, value: $0)
	})				    
	static let allCards : [Card] = AllSpades + AllDiamonds + AllHearts + AllClubs
}
