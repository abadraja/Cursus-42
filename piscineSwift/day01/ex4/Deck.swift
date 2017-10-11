import Foundation

class Deck : NSObject
{
	var cards : [Card] = Deck.allCards
		var discards : [Card] = []
		var outs : [Card] = []

		init(toShuffle : Bool) {
			if toShuffle{
				self.cards.randomaize()
			}
		}

	override var description: String{
		return "\(cards)"
	}

	func draw() -> Card? {
		if cards.first != nil {
			let temp = cards.first!
				outs.append(cards.first!)
				cards.removeFirst()
				return temp
		}
		return nil
	}

	func fold(c: Card){
		if outs.contains(c){
			discards.append(c)
				outs.remove(at: outs.index(of: c)!)
		}
	}


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
extension Array
{
	mutating func randomaize() {
		if count < 2 { return }

		for i in 0 ..< count - 1 {
			let j = Int(arc4random_uniform(UInt32(count - i))) + i
				if i != j {
					swap(&self[i], &self[j])
				}
		}
	}
}
