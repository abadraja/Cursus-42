//
//  Shape.swift
//  MotionCube
//
//  Created by Alen Badrajan on 4/25/17.
//  Copyright © 2017 abadraja. All rights reserved.
//

import UIKit
import Foundation

class Shape: UIView
{
    
    let colors :[UIColor] = [.black, .green, .blue, .purple, .red, .cyan]
    override public var collisionBoundsType: UIDynamicItemCollisionBoundsType {
        return .path
    }
    
    override public var collisionBoundingPath: UIBezierPath
    {
        return UIBezierPath(roundedRect: CGRect(x: -bounds.size.width / 2.0, y: -bounds.size.height / 2.0, width: bounds.width, height: bounds.height), cornerRadius: self.layer.cornerRadius)
    }
    
    init(o : CGPoint)
    {
        var origin = o
        origin.x -= 50
        origin.y -= 50
        let size = CGSize(width: 100, height: 100)
        let rect = CGRect(origin: origin, size: size)
            
        super.init(frame: rect)
        if (arc4random_uniform(UInt32(2)) == 1)
        {
            self.layer.cornerRadius = 50
        }
        self.backgroundColor = colors[Int(arc4random_uniform(UInt32(6)))]

    }
        
    required init?(coder aDecoder: NSCoder)
    {
        fatalError("init(coder:) has not been implemented")
    }
}
