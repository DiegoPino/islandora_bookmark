<?php

/**
 * @file
 * Definition of a BookmarkDefaultSessionList object.
 */

/**
 * Class that defines a BookmarkDefaultSessionList object.
 *
 * A BookmarkDefaultSessionList object only difference is that it cannot be
 * deleted.
 */
class BookmarkDefaultSessionList extends BookmarkSession {

  /**
   * Constructor for the BookmarkDefaultSessionList object.
   */
  public function __construct($list_id) {
    parent::__construct($list_id);
    $this->isDeletable = FALSE;
  }

  /**
   * Overwrite to do nothing...
   */
  public function delete() {

  }

  /**
   * Adds PID to a Bookmark.
   */
  public function addPid($pid) {
    // Only set the $_SESSION keys when first $pid is added.
    if (!isset($_SESSION['islandora_bookmark'][$this->bookmarkId])) {
      $_SESSION['islandora_bookmark'][$this->bookmarkId] = $this;
    }
    $this->pidList[] = $pid;
  }

}
