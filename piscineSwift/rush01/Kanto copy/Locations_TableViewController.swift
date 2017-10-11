//
//  Locations_TableViewController.swift
//  Kanto
//
//  Created by Alen Badrajan on 4/22/17.
//  Copyright © 2017 abadraja. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class Locations_TableViewController: UITableViewController {

    let locations = ["42","Chisinau","Hell"]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    
    
    // MARK: - Table view data source

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (geoLoc.count)
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! Cell_TableViewCell
        
        cell.Location.text = geoLoc[indexPath.row].0
        
        return (cell)
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath)
    {
//        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! Cell_TableViewCell
        kek = indexPath.row
        
    }

}
