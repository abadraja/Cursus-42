import Foundation

class Card : NSObject
{
	let value : Value
		let color : Color

		init(color : Color, value : Value) {
			self.value = value
				self.color = color
		}

	override var description: String
	{
		return ("Current card is \(self.value) of \(self.color)")
	}
	override func isEqual(_ object: Any?) -> Bool {

		if let object = object as? Card {
			return value == object.value && color == object.color
		} else {
			return false
		}
	}
}
