//
//  ViewController.swift
//  MotionCube
//
//  Created by Alen Badrajan on 4/24/17.
//  Copyright © 2017 abadraja. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    public var shapes = [UIView?]()
    public var animator : UIDynamicAnimator?
    var gravity = UIGravityBehavior()
    var boundaries = UICollisionBehavior()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let gesture = UIPanGestureRecognizer(target: self, action: #selector(panGesture(gesture:)))
        view.addGestureRecognizer(gesture)
  
    }
    
    var ex = false
    var diffX:CGFloat = 0.0
    var diffY:CGFloat = 0.0
    
    @IBAction func tapGesture(_ sender: UITapGestureRecognizer)
    {
        print("\(sender.location(in: view))")
        let o = sender.location(in: view)
        let a = Shape.init(o:o)
        view.addSubview(a)
        shapes.append(a)
        print(shapes)
        
        
        //init animator
        animator = UIDynamicAnimator(referenceView: self.view)
        
        //add gravity
        gravity.addItem(a)

        
        //collision
        boundaries.addItem(a)
        boundaries.translatesReferenceBoundsIntoBoundary = true

        animator?.addBehavior(gravity)
        animator?.addBehavior(boundaries)
    }
    var i = 0
    func panGesture(gesture : UIPanGestureRecognizer)
    {
        
        switch gesture.state
        {
        case .began:
            for a in shapes
            {
                
                let o = gesture.location(in: view)
                let b = a?.frame
                if (b?.contains(o))!
                {
                    ex = true
                    diffX = CGFloat(a!.center.x) - CGFloat(o.x)
                    diffY = CGFloat(a!.center.y) - CGFloat(o.y)
                    
                    break
                }
                i += 1
            }
        case .changed:
//            for a in shapes
//            {
            if ex {
                animator?.removeAllBehaviors()
                shapes[i]?.center = gesture.location(in: view)
//                a?.center.x = diffX
//                a?.center.y = diffY
            
            }
        case .ended:
            print("Ended")
            i = 0
            ex = false
            for a in shapes
            {
            animator = UIDynamicAnimator(referenceView: self.view)
            
            gravity.addItem(a!)
            
            //collision
            boundaries.addItem(a!)
            boundaries.translatesReferenceBoundsIntoBoundary = true
            
            animator?.addBehavior(gravity)
            animator?.addBehavior(boundaries)
                break
            }
            
        case .failed, .cancelled:
            print("Failed/Canceled")
        case .possible:
            print("Posible")
            
        }
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

