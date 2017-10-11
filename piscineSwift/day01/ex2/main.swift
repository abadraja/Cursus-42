print("Available colors : ")
for colors in Color.allColors
{
	    print(colors, terminator: ", ")
}

print("\n\nAvailable Numbers are : ")
for nums in Value.allValues
{
	    print(nums, terminator: ", ")
}


var diamond7 = Card(color: Color.Diamons, value: Value.Seven)
print("\n\nCart Test: \(diamond7.description)")

var clubsAce = Card(color: Color.Clubs, value: Value.Ace)
print("Cart Test 2: \(clubsAce.description)")

var heartsQueen = Card(color: Color.Hearts, value: Value.Queen)
print("Cart Test 3: \(heartsQueen.description)")

var Spades10 = Card(color: Color.Spades, value: Value.Ten)
print("Cart Test 4: \(Spades10.description)")

//=======ex02=====
for c in Deck.allCards
{
	    print(c, terminator: "\n")
}


